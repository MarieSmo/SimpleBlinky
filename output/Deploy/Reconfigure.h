#ifndef RECONFIGURE_H
#define RECONFIGURE_H

namespace reconfigure {
	
	/*
	 * The update result is used to signal back to the engine once reconfiguration is executed
	 */
	typedef enum {
		CONTINUE   = 0, //Engine continues by evaluating glue and executing, SKIP reconfigure
		SKIP_CYCLE = 1, //Engine skips evaluating glue, and goes back to evaluating conditions
		HALT	   = 2  //Engine terminates execution
	} UPDATE_RESULT;


	/*
	 * Initialize the reconfiguration layer
	 * Executed once, when the engine is initializing
     */
    void init();

	/*
	 * Invoked when the reconfiguration layer is called by the engine.
	 * Requires: at least one condition in the condition pools to evaluate to true.
	 * notifications is a set of integers that are associated with conditions
	 */
    UPDATE_RESULT update(bipscheduler::CNotify * notifications);

	void complete();
}

#endif
