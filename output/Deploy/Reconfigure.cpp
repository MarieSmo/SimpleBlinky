#include<vector>
#include<assert.h>
#include<set>
#include<Reconfigure.h>
#include<SimpleBlinky_dynamic.cpp>
#include <bits/stdc++.h>

using namespace SimpleBlinky;

/*
 * Skeleton implementation, which does no reconfiguration
 */
namespace reconfigure {

    double time_drbip = 0.0;
    clock_t drbipbegin, drbipend;

    int maxexec = 0;

    #ifdef PERFMODE
    unsigned int max_motifs     = 0;
    unsigned int max_components = 0;
    unsigned int max_conditions = 0;
    #endif

    void snapshotDRBIP() {
    	  for(auto motif = motifs.begin(); motif != motifs.end(); ++motif) {
		      cout << "<TRACE> <DRBIP> snapshot motif ";
		      (*motif)->tracename(cout);
		      cout << " ";
		      (*motif)->tracestate(cout);
		      cout << endl;
	      }
	  }

    void loop() {
        bool updated = true;

        #ifndef PERFMODE
        snapshotBIP("BIP");
        #endif

        //Reconfigure Fixpoint
        while (updated) {


          updated = false;

          for (auto motif = motifs.begin(); motif != motifs.end(); ++motif) {
            updated = (*motif)->reconfigure();
            if(updated) break;
          }

          if(updated) {
            //cout << "[DRBIP] [RLOOP-CR] Changes detected continuing reconfiguration" << endl;
            continue;
          }




          for(auto imr = globalrules.begin(); imr != globalrules.end(); ++imr) {
            updated = (*imr)->execute();
            if(updated) break;
          }


          if(updated) {
            //cout << "[DRBIP] [RLOOP-IMR] Changes detected continuing reconfiguration" << endl;
            continue;
          }
        }


        //cout << "[DRBIP] Updating Interactions and Triggers" << endl;

        //Stable Loop: interactions + triggers
        for (auto motif = motifs.begin(); motif != motifs.end(); ++motif) {
          (*motif)->computeInteractions();
          (*motif)->addTriggers();
        }
        for(auto imr = globalrules.begin(); imr != globalrules.end(); ++imr)
          (*imr)->addTriggers();

      #ifndef PERFMODE
      snapshotDRBIP();
      snapshotBIP("DRBIP");
      #endif
      //Increment number of reconfiguration steps
	    bipscheduler::TRACE_SID = (bipscheduler::TRACE_SID + 1) % INT_MAX;
    }

    void init() {

      srand(time(nullptr));


    #ifndef PERFMODE
	  cout << "<TRACE> <DRBIP> init begin " << PACK_NAME << endl;
	  #endif
      //cout << "[DRBIP] Init : Applying initializer rule" << endl;
      initializer();
    #ifndef PERFMODE
    snapshotDRBIP();
    snapshotBIP("DRBIP");
    #endif
      //cout << "[DRBIP] Init : Reconfiguring" << endl;
      loop();


    #ifndef PERFMODE
      dumpConditions();
      dumppools();
	  cout << "<TRACE> <DRBIP> init end" << endl;
	  #endif
      //cout << "[DRBIP] Initialization Complete" << endl;

    }


    //Generic Execution
    UPDATE_RESULT update(CNotify* notifications) {

      //Stop after 100 reconfigurations for testing purposes
      /*
      if(maxexec++ > 3) {

        dumppools();
        dumpConditions();
        return HALT;
      }*/

      assert(!notifications->empty());
      #ifndef PERFMODE
      cout << "[DRBIP] (!)";

      for(CNotify::iterator niter = notifications->begin(); niter != notifications->end(); ++niter)
        cout << " " << (*niter);
      cout << endl;
      #endif

      #ifdef PERFMODE
      drbipbegin = clock();
      #endif

      loop();

      #ifdef PERFMODE
      drbipend = clock();
      time_drbip += (double)(drbipend - drbipbegin) / CLOCKS_PER_SEC;


      if(motifs.size() > max_motifs) max_motifs = motifs.size();
      if(root->components.size() > max_components) max_components = root->components.size();
      unsigned int cond = 0;

      for(auto topcond  = root->conditions.begin(); topcond != root->conditions.end(); ++topcond)
        cond += (*topcond)->conditions.size();

      if(cond > max_conditions) max_conditions = cond;
      #endif
      //dumpConditions();
      //dumppools();
      #ifndef PERFMODE
      cout << "[DRBIP] Reconfiguration Complete (M:" << motifs.size() << "|IMR:" << globalrules.size() << ")" << endl;
      #endif
      notifications->clear();

      // Go back to evaluate conditions
      return SKIP_CYCLE;
    }

    void complete() {
      #ifdef PERFMODE
      cout << "drbip-time: " <<  fixed
	       << time_drbip << setprecision(5);
	    cout << " sec" << endl;

      cout << "drbip-phases: " << bipscheduler::TRACE_SID - 1 << endl;

      cout << "drbip-imr: " << nrules_imr << endl;
      cout << "drbip-rr: " << nrules_rr << endl;
      cout << "drbip-ir: " << nrules_ir << endl;

      cout << "drbip-create-comps: " << nobj_create_atoms << endl;
      cout << "drbip-destroy-comps: " << nobj_destroy_atoms << endl;
      cout << "drbip-create-motifs: " << nobj_create_motifs << endl;
      cout << "drbip-destroy-motifs: " << nobj_destroy_motifs << endl;

      cout << "drbip-max-motifs: " << max_motifs << endl;
      cout << "drbip-max-comps: " << max_components << endl;
      cout << "drbip-max-conditions: " << max_conditions << endl;
      #endif
    }


}
