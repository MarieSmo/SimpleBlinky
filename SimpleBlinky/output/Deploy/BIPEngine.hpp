#ifndef MODELI_H
#define MODELI_H


#include<vector>
#include<set>
#include<map>
namespace bipscheduler {

	typedef enum {
		NO_ERROR = 0,
		NON_DETERMINISTIC_PETRI_NET = 1,
		NON_ONE_SAFE_PETRI_NET = 2,
		CYCLE_IN_PRIORITIES = 3,
		CYCLE_IN_ATOM_PRIORITIES = 4,
		ATOM_INVARIANT_VIOLATION = 5,
		UNEXPECTED_EVENT = 6,
		COMPOUND_INVARIANT_VIOLATION = 7
	} ErrorType;
	
	unsigned int TRACE_SID = 0;
	
	/** 
	 * Interface for atomic components
	 */
	class AtomType {
		public:
		/*
		 * Initialize an atomic component, needed to be called 
		 * after creating it
		 */
		virtual ErrorType 	initialize() 		= 0;
	
		//Tracer
		virtual void tracename(ostream & out)   = 0;
		virtual void dumpState(ostream & out)   = 0;
	};	
	
	/** 
	 * Interface for the glue.
	 * Contains basically a boolean predicate to evaluate
	 */
	class Interaction {
		public:
	 	//Check if enabled, no evaluation
		virtual bool 		isEnabled() 		= 0;
		//Evaluate condition and return enabled status
		virtual bool 		checkSetEnabled() 	= 0;
		//Execute associated interaction
		virtual ErrorType 	execute() 			= 0;
		//Pretty print the interaction to display when verbose is on
		virtual void 		print()				= 0;
	
		//Tracer
		virtual void tracename(ostream & out)   = 0;
	};
	
	/**
	 * Interface for a model condition
	 * These conditions are evaluated on the model by the engine
	 */
	class Condition {
		public:
		//Return the boolean value of the condition (without evaluating)
		virtual bool getValue() = 0;
		//Evaluate the expression and return its value
		virtual bool evaluate() = 0;
		//Return a notification ID, this is used to signal an event to the reconfiguration layer
		virtual int  notifyID() = 0;
	};
	
	/*
	 * The engine uses "pools" of either interactions or conditions
	 * Pools are basically a set of either interactions or conditions
	 * used to easily remove/add a bulk of interactions at runtime
	 */
	typedef std::set<Interaction*> IPool;
	typedef std::set<int> CNotify;
	
	class CPool {
	public:
	  std::set<Condition*> conditions;
	  //Flagged true if at least one condition in pool evaluates to true
	  bool triggered = false;
	};
	
	/*
	 * Create a new interaction pool.
	 * Returns a new interaction pool that can be used to add and remove interactions
	 */
	IPool* poolCreate();
	/*
	 * Delete an existing pool
	 */
	void poolDelete(IPool*);
	
	
	/** 
	 * Interface for the BIP System (flattened)
	 */
	class BIPSystem {
		public:
		std::set<AtomType *> components;
		std::set<IPool*>        glue;
		std::set<CPool*>        conditions;
	
		virtual void 		initialize()		= 0;
	};
	
	/** 
	 * The single running BIP System
	 */
	BIPSystem * root;

}
#endif
