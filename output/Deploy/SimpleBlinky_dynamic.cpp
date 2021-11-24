#include<drbip.h>
#include<SimpleBlinky.cpp>
#include<SimpleBlinkyTypes.hpp>
#include <bits/stdc++.h>

using namespace SimpleBlinky;

namespace reconfigure {

    set<Motif*> motifs;
    set<ExecutableRule*> globalrules;
    const char * const PACK_NAME = "SimpleBlinky";
    #ifdef PERFMODE
    unsigned int nrules_imr = 0;
    unsigned int nrules_ir  = 0;
    unsigned int nrules_rr  = 0;
    unsigned int nobj_create_atoms = 0;
    unsigned int nobj_destroy_atoms = 0;
    unsigned int nobj_create_motifs = 0;
    unsigned int nobj_destroy_motifs = 0;
    #endif

    class MotifSet {
    public:
        set<AT__CORE*> S_CORE;
        set<AT__SURFACES*> S_SURFACES;
        int size() {
            int sz = 0;
            sz += S_CORE.size();
            sz += S_SURFACES.size();
            return sz;
        }
        void tracestate(ostream & out) {
            for(auto iter_0 = S_CORE.begin(); iter_0 != S_CORE.end(); iter_0++){
                cout << " ";
                (*iter_0)->tracename(out);
            }
            for(auto iter_1 = S_SURFACES.begin(); iter_1 != S_SURFACES.end(); iter_1++){
                cout << " ";
                (*iter_1)->tracename(out);
            }
        }
    };
    
    MotifSet global;

    //Spawn functions

    AT__CORE* spawnCORE(int arg0) {
        AT__CORE* obj = new AT__CORE(arg0);
        global.S_CORE.insert(obj);
        root->components.insert((AtomType*) obj);
        obj->initialize();
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> spawn component ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_create_atoms++;
            #endif
        return obj;
    }
    void despawnCORE(AT__CORE* obj) {
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> despawn component ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_destroy_atoms++;
            #endif
        root->components.erase((AtomType*) obj);
        global.S_CORE.erase(obj);
        delete obj;
    }


    AT__SURFACES* spawnSURFACES() {
        AT__SURFACES* obj = new AT__SURFACES();
        global.S_SURFACES.insert(obj);
        root->components.insert((AtomType*) obj);
        obj->initialize();
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> spawn component ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_create_atoms++;
            #endif
        return obj;
    }
    void despawnSURFACES(AT__SURFACES* obj) {
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> despawn component ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_destroy_atoms++;
            #endif
        root->components.erase((AtomType*) obj);
        global.S_SURFACES.erase(obj);
        delete obj;
    }


    class MotifSimple : public Motif {
    public:
        MotifSet comps;
        static unsigned int icounter;
        int sid;
        int icount;
        SimpleBlinkyMap structure;
        DefaultAddressing address;
        MotifSimple();
        void tracename (ostream & out) override;
        void tracestate(ostream & out) override;
    };
    class BlockInitializer : public Rule {
    public:
        MotifSimple* motif;
        IPool * connectors;
        static unsigned int icounter;
        int sid;
        int icount;
        BlockInitializer() {
            connectors = poolCreate();
            icount = (icounter++) % INT_MAX;
            sid    = bipscheduler::TRACE_SID;
        }
        virtual Motif* getMotif() { return (Motif*) motif; }
    
        ~BlockInitializer() {
            cleanup(connectors);
            poolDelete(connectors);
        }
    
        bool execute() {
            return applyAll();
        }
        bool applyAll() {
            bool applied = false;
            cleanup(connectors);
            for(auto i_arg_s = motif->comps.S_SURFACES.begin(); i_arg_s != motif->comps.S_SURFACES.end(); ++i_arg_s ){
                auto v_s = *i_arg_s;
                if(!(true)) continue;
                for(auto i_arg_c = motif->comps.S_CORE.begin(); i_arg_c != motif->comps.S_CORE.end(); ++i_arg_c ){
                    auto v_c = *i_arg_c;
                    if(!(motif->structure.isConnected(motif->address((AtomType*)v_c), motif->address((AtomType*)v_s)))) continue;
                    apply(v_s,v_c);
                    applied = true;
                }
            }
            return applied;
        }
        void apply(AT__SURFACES* s, AT__CORE* c){
            Interaction * myConnector = new ConnectCoreAndSurface(s, c);
            connectors->insert(myConnector);
            #ifndef PERFMODE
            cout << "<TRACE> <DRBIP> apply ";
            tracename(cout);
            cout << " with";
            cout << " ";
            s->tracename(cout);
            cout << " ";
            c->tracename(cout);
            cout << endl;
            cout << "<TRACE> <DRBIP> spawn interaction ";
            myConnector->tracename(cout);
            cout << " ";
            s->tracename(cout);
            cout << " ";
            c->tracename(cout);
            cout << endl;
            #endif
            #ifdef PERFMODE
            nrules_ir++;
            #endif
        }
        bool addTriggers() {
            return false;
        }
    void tracename(ostream & out) {
        out << "IR BlockInitializer_" << sid << "_" << icount;
        out << " in ";
        motif->tracename(out);
    }
    };
    unsigned int BlockInitializer::icounter = 0;
    
    MotifSimple::MotifSimple(){
        BlockInitializer* rule0 = new BlockInitializer();
        rule0->motif = this;
        ir.push_back(rule0);
        icount = (icounter++) % INT_MAX;
        sid    = bipscheduler::TRACE_SID;
    }
    void MotifSimple::tracename(ostream & out) {
        out << "MotifSimple_" << sid << "_" << icount;
    }
    void MotifSimple::tracestate(ostream & out) {
        comps.tracestate(out);
    }
    unsigned int MotifSimple::icounter = 0;


    set<MotifSimple*> S_MotifSimple;

    MotifSimple* spawnMotifSimple() {
        MotifSimple* obj = new MotifSimple();
        S_MotifSimple.insert(obj);
        motifs.insert((Motif*) obj);
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> spawn motif ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_create_motifs++;
            #endif
        return obj;
    }
    void despawnMotifSimple(MotifSimple* obj) {
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> despawn motif ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_destroy_motifs++;
            #endif
        S_MotifSimple.erase(obj);
        motifs.erase((Motif*) obj);
        delete obj;
    }


    void initializer() {
        MotifSimple* b1=spawnMotifSimple();
        AT__CORE* core=spawnCORE(1);
        AT__SURFACES* surfaces=spawnSURFACES();
    }
}