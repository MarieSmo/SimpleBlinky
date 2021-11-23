#ifndef DRBIP_H
#define DRBIP_H

#include<BIPEngine.hpp>
#include<iostream>
#include<map>

using namespace bipscheduler;

set<int>* seq(int start, int end) {
  set<int>* mySet = new set<int>();
  for(int i = start; i <= end; i++)
    mySet->insert(i);

  return mySet;
}

namespace reconfigure {

    class Motif;
    class ExecutableRule;

    //Bind a notification ID to a set of rules
    typedef map<int, set<ExecutableRule*>*> RMap;
    //Motif events (ONGOING) for observers, changes to either component set or deployment
    enum MotifEvent {SET, DEPLOYMENT};


    class Node {};

    //  A rule that can be executed
    class ExecutableRule {
    public:
        //virtual bool isEnabled(RMap *, CNotify*)  = 0;
        //virtual bool execute(RMap* map, CNotify * notify) = 0;
        virtual bool execute() = 0;
        virtual bool addTriggers() = 0;

		//Trace
		virtual void tracename(ostream & out) = 0;
    };
    // Standard Motif Rule, IR/RR
    class Rule : public ExecutableRule {
    public:
        //virtual void init(RMap *) = 0;
        virtual Motif* getMotif() = 0;
        virtual ~Rule()  {};
    };

    // Observer for changes in motif structure
    class MotifObserver {
    public:
        virtual void onMotifEvent(Motif * motif, MotifEvent, void * data) = 0;
    };

    // Creates a notification ID in a channel, to add rules to it
    RMap::iterator createOrFind(RMap * map, int nspace) {
      RMap::iterator search = map->find(nspace);
      if (search == map->end()) {
        std::pair<RMap::iterator, bool> res = map->insert(RMap::value_type(nspace, new set<ExecutableRule*>));
        return res.first;
      }
      return search;
    }

    // Inter-motif rule
    class InterMotifRule : public ExecutableRule {
    public:
        //virtual void initialize(RMap*) 	= 0;
        //virtual void destroy()          = 0;
        virtual ~InterMotifRule(){};
    };

    class Motif {
    public:
        vector<Rule*> ir;
        vector<Rule*> cr;
        //One set per event
        set<MotifObserver*> observers[2];

        //virtual void initialize(RMap*) 	= 0;
        //virtual void destroy()          = 0;

		virtual void tracename(ostream & out) = 0;
		virtual void tracestate(ostream & out) = 0;

        // Compute Motif fixed point
        virtual bool reconfigure() {
            bool modified = false;

            for(auto iter = cr.begin(); iter != cr.end(); ++ iter)
              if((*iter)->execute())
                modified = true;

            return modified;
        }
        virtual bool computeInteractions() {
          bool modified = false;
          for (auto iter = ir.begin(); iter != ir.end(); ++iter) {
            if((*iter)->execute())
              modified = true;
          }

          return modified;
        }

        virtual bool addTriggers() {
          bool added = false;
          for(auto iter = ir.begin(); iter != ir.end(); ++iter)
            added = (*iter)->addTriggers() || added;

          for(auto iter = cr.begin(); iter != cr.end(); ++iter)
            added = (*iter)->addTriggers() || added;

          return added;
        }

        //Manage observers
        virtual void addObserver(MotifObserver * obs, MotifEvent ev)  {
            observers[ev].insert(obs);
        }
        virtual void removeObserver(MotifObserver * obs, MotifEvent ev)  {
          observers[ev].erase(obs);
        }


        ~Motif() {
          for(auto rule = ir.begin(); rule != ir.end(); ++rule)
            delete *rule;

          for(auto rule = cr.begin(); rule != cr.end(); ++ rule)
            delete *rule;
        }

    };


    // Probability as a condition
    class CProb : public Condition {

    private:
        float prob = 0;
        int notify = 0;
        bool lastEval = false;

    public :

        CProb(float prob, int notify) { this->notify = notify; this->prob = prob; }

        bool getValue() override {
          return lastEval;
        }

        bool evaluate() override {
          float choice = (((float) rand()) / ((float)RAND_MAX));
          lastEval = prob >= choice;
          return lastEval;
        }

        int notifyID() override {
          return notify;
        }

        void reset() {
          lastEval = false;
        }
    };

    // Always true condition
    class CTrue : public Condition {
    public:
        bool getValue() override {
          return true;
        }

        bool evaluate() override {
          return true;
        }

        int notifyID() override {
          return 0;
        }
    };


    // Debug print all interaction pools
    void dumppools() {
      std::cout << "[DEBUG] Dumping All Interactions" << std::endl;
      for(auto poolit = root->glue.begin(); poolit != root->glue.end(); ++ poolit){
        IPool::iterator it;
        for(it = (*poolit)->begin(); it != (*poolit)->end(); ++it) {
          (*it)->print();
          std::cout << std::endl;
        }
      }
    }

    void cleanup(IPool * connectors) {
      if(connectors == NULL) return;

      for(auto con = connectors->begin(); con != connectors->end(); ++con)
        delete (*con);

      connectors->clear();
    }

    void snapshotBIP(char * prefix) {
      for(auto iter = root->components.begin(); iter != root->components.end(); ++iter) {
        cout << "<TRACE> <" << prefix <<  "> snapshot component ";
        (*iter)->tracename(cout);
        cout << " { ";
        (*iter)->dumpState(cout);
        cout << " }";
        cout << endl;
      }
    }

    void cleanup(CPool * conditions) {
      if(conditions == NULL) return;


      for(auto cond = conditions->conditions.begin(); cond != conditions->conditions.end(); ++ cond)
        delete (*cond);

      conditions->conditions.clear();
      conditions->triggered = false;
    }

    void dumpConditions() {
      std::cout << "[DEBUG] Dumping All Conditions" << std::endl;
      for(auto topcond  = root->conditions.begin(); topcond != root->conditions.end(); ++topcond)
        cout << *topcond << " (" << (*topcond)->triggered << ") "
             << (*topcond)->conditions.size() << endl;
    }

    void clearAllConditions() {
      for(auto topcond  = root->conditions.begin(); topcond != root->conditions.end(); ++topcond) {
        cleanup(*topcond);
        delete *topcond;
      }
      root->conditions.clear();
    }
    class DefaultAddressing {
    public:
        map<AtomType*, Node*> nodeMap;

        void bind(AtomType* atom, Node* node) {
          nodeMap.insert(pair<AtomType*, Node*>(atom, node));
        }
        Node * operator()(AtomType * atom) {
          auto value = nodeMap.find(atom);
          if(value != nodeMap.end())
            return value->second;
          else
            return NULL;
        }

        void clear() {
          nodeMap.clear();
        }

        void merge(DefaultAddressing * address) {
          nodeMap = std::move(address->nodeMap);
          delete address;
        }

        void remove(AtomType * atom) {
          nodeMap.erase(atom);
        }

        void removeAll(Node * node) {
          set<AtomType*> toRemove;
          toRemove.clear();

          for(auto iter = nodeMap.begin(); iter != nodeMap.end(); ++iter)
            if(iter->second == node)
              toRemove.insert(iter->first);

          for(auto iter = toRemove.begin(); iter != toRemove.end(); ++iter)
            remove(*iter);
        }

    };


    //Check an atom is in a given state
    template<class T> inline bool checkState(T * atom, int state) {
      return ((atom->_state[state/(8*sizeof(unsigned int))]
               & (((unsigned int) 1) << state%(8*sizeof(unsigned int)))) != 0);
    }

    template<class T, int STATE, int NOTIFY> class CondState : public Condition {
    private:
        bool save = false;
    public:
        T * atom = nullptr;

        CondState(T * atom) {
          this->atom = atom;
        }

        bool getValue() override {
          return save;
        }

        static bool eval(T * atom) {
          return checkState<T>(atom, STATE);
        }


        bool evaluate() override {
          assert(atom != nullptr);
          save = eval(atom);
          return save;
        }

        int notifyID() override {
          return NOTIFY;
        }
    };


}

#endif
