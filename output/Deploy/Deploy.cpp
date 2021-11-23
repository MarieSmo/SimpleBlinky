#ifndef BIP_ENGINE
#define BIP_ENGINE 1
// User include given in @cpp annotation
#include <ext.cpp>

// #include <BipError.hpp>
// #include <UnexpectedEventError.hpp>
// #include <AtomInvariantViolationError.hpp>
// #include <CompoundInvariantViolationError.hpp>
#include <AtomExternalPort.hpp>
#include <BIPEngine.hpp>
#include <Reconfigure.cpp>

#include <signal.h>
#include <unistd.h>
#include <bits/stdc++.h> 

#include <assert.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <stack>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>

namespace Engine {
  const int SIGBIP = SIGUSR1;
};

namespace bipscheduler {

  pid_t pid = 0;

  volatile unsigned int nbNotifications = 0;
  unsigned int nbTreatedNotifications = 0;

  void handleSignals(int signum) {
    nbNotifications++;
  }

  void waitForNotifications() {
    // then wait for notifications
    sigset_t maskOld, maskSIGBIP;

    sigemptyset(&maskSIGBIP);
    sigaddset(&maskSIGBIP, Engine::SIGBIP);

    sigprocmask(SIG_BLOCK, &maskSIGBIP, &maskOld);

    if (nbTreatedNotifications == nbNotifications) {
      sigsuspend(&maskOld);
    }

    sigprocmask(SIG_UNBLOCK, &maskSIGBIP, NULL);
  }

  bool verbose = true;
  unsigned int limit = 0;
  bool execute = true;
  bool random = true;


  ErrorType initialize() {
    pid = getpid();
    signal(Engine::SIGBIP, handleSignals);
  
    SimpleBlinky::initializeModel();
  
    root->initialize();
  
  
  
    return NO_ERROR;
  }

  ErrorType checkExternalPort(AtomExternalPort &port, bool portIsWaiting, bool &isWaiting) {
    port.setIsEnabled(false);
    isWaiting = false;
  
    bool snapshotHasEvent = port.hasEvent();
  
    if (portIsWaiting && snapshotHasEvent) {
      port.setIsEnabled(true);
    }
    else if (portIsWaiting && !snapshotHasEvent) {
      isWaiting = true; 
    }
    else if (!portIsWaiting && snapshotHasEvent) {
      // unexpected event
      if (port.policy() == REMEMBER) {
        // nothing to do in this case!
      }
      else if (port.policy() == IGNORE) {
        port.purgeEvents();
      }
      else if (port.policy() == ERROR) {      
        return UNEXPECTED_EVENT;
      }
      else {
        assert(false);
      }
    }
    else {
      assert(!portIsWaiting && !snapshotHasEvent);
    }
  
    return NO_ERROR;
  }

  ErrorType checkExternals(unsigned int &externals, unsigned int &waiting) {
    externals = 0;
    waiting = 0;
  
  
    return NO_ERROR;
  }

  ErrorType update(unsigned int &interactions, unsigned int &internals, unsigned int &externals, unsigned int &waiting, std::vector<Interaction*> &enabledInteractions) {
    interactions = 0;
    internals = 0;
    externals = 0;
    waiting = 0;
  
    nbTreatedNotifications = nbNotifications;
  
    ErrorType error = checkExternals(externals, waiting);
  
    if (error != NO_ERROR) {
      return error;
    }
  
    if (externals == 0) {
  		for (auto poolit=root->glue.begin(); poolit!=root->glue.end(); ++poolit){
  			IPool::iterator it;
  			for(it = (*poolit)->begin(); it != (*poolit)->end(); ++it) 
  			if((*it)->checkSetEnabled()) {
  				enabledInteractions.push_back((*it));
  				++interactions;
  			}
  		}
  
  		//TODO internal ports
  
  	
  	
    }
  
    return NO_ERROR;
  }


  ErrorType executeFirst(bool &deadlock, bool &waiting) {
  	//Not implemented
  	assert(false);
    deadlock = true;
  
    return NO_ERROR;
  }

  ErrorType executeChoice(unsigned int choice, unsigned int interactions, unsigned int internals, unsigned int externals, std::vector<Interaction*> &enabledInteractions, bool _print) {
    if (choice < interactions) {
  	if(choice >= 0 && choice < enabledInteractions.size()) {
  		  Interaction * chosen = enabledInteractions.at(choice);
  		  if(chosen->isEnabled()) {
  			  #ifndef PERFMODE
  		      if(_print && bipscheduler::verbose) {
  		          chosen->print();
  		          cout << endl;
  				  cout <<"<TRACE> <BIP> interaction ";
  				  chosen->tracename(cout);
  				  cout << endl;
  		      }
  			  #endif
  		      return chosen->execute();
  		  }
  	  }
  	  else {
  		  assert(false);
  	  }
    }
    else if (choice < interactions + internals) {
      choice -= interactions;
  
      
    }
    else {
      assert(choice < interactions + internals + externals);
  
      choice -= interactions + internals;    
  
      
    }
  
    return NO_ERROR;
  }

  ErrorType checkCompoundInvariants() {
  
    return NO_ERROR;
  }

  /*
   * Evaluate the conditions on the model
   * Each true condition adds its notification ID to the set of notifications
   */
  void evalConditions(CNotify * notifications) {
   for(auto iter = root->conditions.begin(); iter != root->conditions.end(); ++ iter) {
      (*iter)->triggered = false;
      for (auto cond = (*iter)->conditions.begin(); cond != (*iter)->conditions.end(); ++cond)
        if ((*cond)->evaluate()) {
          notifications->insert((*cond)->notifyID());
          (*iter)->triggered = true;
        }
    }
  }

  ErrorType run() {
  
    // state
    unsigned int stateIndex = 0;
  
    ErrorType invariantsError = checkCompoundInvariants();
  
    if (invariantsError != NO_ERROR) {
      return invariantsError;
    }
  
    CNotify notifications;
  
    #ifdef PERFMODE
    clock_t begin, end;
    double time_bip = 0.0;
    #endif
  
  
    while (limit == 0 || stateIndex < limit) {
  
  	evalConditions(&notifications);
  
  
      if(!notifications.empty()) {
        reconfigure::UPDATE_RESULT res = reconfigure::update(&notifications);
  
        if (res == reconfigure::SKIP_CYCLE)
          continue;
        else if (res == reconfigure::HALT)
          break;
      }
  
  	#ifdef PERFMODE
  	begin = clock();
  
      #endif
  
      if (bipscheduler::random) {
        unsigned int interactions = 0;
        unsigned int internals = 0;
        unsigned int externals = 0;
        unsigned int waiting = 0;
        std::vector<Interaction*> enabledInteractions;
        
        ErrorType updateError = update(interactions, internals, externals, waiting, enabledInteractions);
        
        if (updateError != NO_ERROR) {
          return updateError;
        }
        
        if ((interactions + internals + externals) == 0) {
          if (waiting > 0) {
            // nothing to execute now but waiting for external events
            waitForNotifications();
        
            continue;
          }
          else {
            // deadlock
            if (bipscheduler::verbose) cout << "[BIP ENGINE]: ";
            if (bipscheduler::verbose) cout << "state #" << stateIndex << ": ";
            if (bipscheduler::verbose) cout << "deadlock!";
            if (bipscheduler::verbose) cout << endl;
        
            break;
          }
        }
        
        #ifndef PERFMODE
        if (bipscheduler::verbose) cout << "[BIP ENGINE]: ";
        if (bipscheduler::verbose) cout << "state #" << stateIndex << ": ";
        if (bipscheduler::verbose) {
          if (interactions + internals + externals == 0) {
            if (bipscheduler::verbose) cout << "deadlock!";
          }
          else {
            if (interactions > 0) {
              cout << interactions << " interaction";
              if (interactions > 1) cout << "s";
            }
        
            if (internals > 0) {
              if (interactions > 0) cout << " and ";
           
              cout << internals << " internal port";
              if (internals > 1) cout << "s";
            }
        
            if (externals > 0) {
              if (interactions + internals > 0) cout << " and ";
        
              cout << externals << " external port";
              if (externals > 1) cout << "s";
            }
        
            cout << ":";
          }
        }
        if (bipscheduler::verbose) cout << endl;
        #endif
        
        unsigned int index __attribute__((unused)) = 0;
        
        
        for(auto poolit =  root->glue.begin(); poolit != root->glue.end(); ++ poolit){
          IPool::iterator it;
          for(it = (*poolit)->begin(); it != (*poolit)->end(); ++it) {
        	  if((*it)->isEnabled()) {
        		  #ifndef PERFMODE
        	      if (bipscheduler::verbose) {
        	          cout << "[BIP ENGINE]: ";
        	          cout << "  [";
        	          cout << index;
        	          cout << "] ";;
        	          (*it)->print();
        	          cout << endl;
        	      }
        		  #endif
        	      ++index;
        	  }
          }
        }
        
        
        
        
        
        unsigned int choice =
          (unsigned int) (interactions + internals + externals) * (rand() / (RAND_MAX + 1.0));
        
        #ifndef PERFMODE
        if (bipscheduler::verbose) cout << "[BIP ENGINE]: ";
        if (bipscheduler::verbose) cout << "-> choose ";
        if (bipscheduler::verbose) cout << "[";
        if (bipscheduler::verbose) cout << choice;
        if (bipscheduler::verbose) cout << "] ";
        #endif
        
        ErrorType executeError = executeChoice(choice, interactions, internals, externals, enabledInteractions, true);
        
        if (executeError != NO_ERROR) {
          return executeError;
        }
      }
      else {
        if (bipscheduler::verbose) cout << "[BIP ENGINE]: ";
        if (bipscheduler::verbose) cout << "state #" << stateIndex << ": ";
              
        bool deadlock = false;
        bool waiting = false;
        
        do {
          nbTreatedNotifications = nbNotifications;
        
          ErrorType executeError = executeFirst(deadlock, waiting);
        
          if (executeError != NO_ERROR) {
            return executeError;
          }
        
          if (deadlock && waiting) {
            waitForNotifications();
          }
        }
        while (deadlock && waiting);
        
        if (deadlock) {
          #ifndef PERFMODE
          if (bipscheduler::verbose) cout << "deadlock!";
          if (bipscheduler::verbose) cout << endl;
          #endif
          break;
        }
        
        ErrorType invariantsError = checkCompoundInvariants();
        
        if (invariantsError != NO_ERROR) {
          return invariantsError;
        }
      }
  
      #ifdef PERFMODE
  	end = clock();
  	time_bip += (double)(end - begin) / CLOCKS_PER_SEC;
      #endif
  
      // increment state index counter
      ++stateIndex;
    }
  
    // handle limits
    if (limit > 0 && stateIndex >= limit) {
      if (bipscheduler::verbose) cout << "[BIP ENGINE]: ";
      if (bipscheduler::verbose) cout << "state #" << stateIndex << ": ";
      if (bipscheduler::verbose) cout << "stop (reached limit of " << limit << " states)";
      if (bipscheduler::verbose) cout << endl;
    }
  
    #ifdef PERFMODE
  	cout << "bip-time: " << fixed 
  	       << time_bip << setprecision(5); 
  	cout << " sec" << endl; 
      cout << "bip-interactions: " << stateIndex - 1 << endl;
    #endif
  
    return NO_ERROR;
  }

	IPool* poolCreate() {
	  IPool* pool = new IPool();
	  root->glue.insert(pool);
	  return pool;
	}
	
	void poolDelete(IPool* pool) {
	  assert(pool != nullptr);
	  pool->clear();
	  delete pool;
	  root->glue.erase(pool);
	}
};




bool isSerializeEnabled() {
  return false; // return bipscheduler::isSerializeEnabled();
}

void serialize(char **cbuf __attribute__((unused)), size_t *clen __attribute__((unused))) {
  // bipscheduler::serialize(cbuf, clen);
}

void deserialize(const char *buf __attribute__((unused)), size_t len __attribute__((unused))) {
  // bipscheduler::deserialize(buf, len);
}

using namespace bipscheduler;

int main(int argc, char **argv) {
  string bipExecutableName = "<bip_executable>";
  
  // set the name of the bip executable
  if (argc > 0) {
    bipExecutableName = string(argv[0]);
  }
  
  // parse options
  for (int i = 1 ; i < argc ; ++i) {
    string option = argv[i];
  
    if (option == "-v" || option == "--verbose") {
      bipscheduler::verbose = true;
    }
    else if (option == "s" || option == "--silent") {
      bipscheduler::verbose = false;
    }
    else if (option == "--explore") {
      bipscheduler::execute = false;
    }
    else if (option == "--disable-fairness") {
      bipscheduler::random = false;
    }
    else if (option == "-l" || option == "--limit") {
      // look for an integer argument
      if (i < argc - 1) {
        ++i;
        std::string argument = argv[i];
        std::stringstream iss(argument);
        iss >> bipscheduler::limit;
  
        if (iss.fail() || bipscheduler::limit == 0) {
          cout << bipExecutableName << ": invalid arguement for '" << option << "', waiting for a non-negative interger" << endl;
          // cout << "Try `" << bipExecutableName << " --help' for more information." << endl;
  
          return EXIT_FAILURE;
        }
      }
      else {
        cout << bipExecutableName << ": missing non-negative integer argument for '" << option << "'" << endl;
        // cout << "Try `" << bipExecutableName << " --help' for more information." << endl;
  
        
        return EXIT_FAILURE;
      }
    }
    else {
      cout << bipExecutableName << ": invalid option -- '" << option << "'" << endl;
      // cout << "Try `" << bipExecutableName << " --help' for more information." << endl;
  
      return EXIT_FAILURE;
    }
  }

  bipscheduler::ErrorType error = initialize();

  if (error == bipscheduler::NO_ERROR) {
    if (bipscheduler::execute) {
	  #ifdef PERFMODE
	  clock_t begin = clock();
	  #endif
      error = bipscheduler::run();
	  #ifdef PERFMODE
	  clock_t end = clock();
	  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      cout << "total-time: " << fixed 
           << time_spent << setprecision(5); 
      cout << " sec" << endl; 
	  #endif 
	  reconfigure::complete();
      
   }
    else {
      if (bipscheduler::verbose) cout << "[BIP ENGINE]: ";
      if (bipscheduler::verbose) cout << "ERROR: missing serialization functions!";
      if (bipscheduler::verbose) cout << endl;
      if (bipscheduler::verbose) cout << "[BIP ENGINE]: ";
      if (bipscheduler::verbose) cout << "ERROR: Try to recompile with option --gencpp-enable-marshalling";
      if (bipscheduler::verbose) cout << endl;
    }
  }

  return error;
}

#endif
