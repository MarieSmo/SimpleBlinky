#ifndef BIPMODEL_SimpleBlinky
#define BIPMODEL_SimpleBlinky 1
/*
 * This file contains all types that are specific to the BIP model from which it is generated
 */

// User include given in @cpp annotation
#include <stdio.h>

// #include <BipError.hpp>
// #include <UnexpectedEventError.hpp>
// #include <AtomInvariantViolationError.hpp>
// #include <CompoundInvariantViolationError.hpp>
#include <AtomExternalPort.hpp>
#include <BIPEngine.hpp>

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

using namespace bipscheduler;

namespace SimpleBlinky {

	/*
	 * Atomic Components
	 */

	
	
	class AT__CORE : public AtomType {
	 public:
		static unsigned int icounter;
		unsigned int sid;
		unsigned int icount;
	
	  // bitvector encoding state
	  unsigned int _state[2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0)];
	
	  // component parameters
	  int _param__id;
	
	
	  // transitions of ports
	  unsigned int _transition__CORE_ASSEMBLE;
	  unsigned int _transition__CORE_DISASSEMBLE;
	;
	
		AT__CORE( int   _param__id ) {
			this->_param__id = _param__id;
		
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
		ErrorType initialize() override {
			// update state of c
			for (unsigned int i = 0 ; i < 2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0) ; ++i) {
			  _state[i] = 0;
			}
			// check for non 1-safety
			if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
			  return NON_ONE_SAFE_PETRI_NET;
			}
			
			_state[1/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
			
			
			
			this->_transition__CORE_DISASSEMBLE = 0;
			
			if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
			  assert(this->_transition__CORE_DISASSEMBLE == 0);
			
			  this->_transition__CORE_DISASSEMBLE = 2;
			}
			
			this->_transition__CORE_ASSEMBLE = 0;
			
			if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
			  assert(this->_transition__CORE_ASSEMBLE == 0);
			
			  this->_transition__CORE_ASSEMBLE = 1;
			}
	
			return NO_ERROR;
		}
	
	//internal port 
		ErrorType port_CORE_ASSEMBLE() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__CORE_ASSEMBLE) {
		    case 1:
		      // execute transition of line TO BE DONE
		      assert((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[1/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      _state[0/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("\033[32mBlock %d\033[0m assembled", this->_param__id);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__CORE_DISASSEMBLE = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__CORE_DISASSEMBLE == 0);
		  
		    this->_transition__CORE_DISASSEMBLE = 2;
		  }
		  
		  this->_transition__CORE_ASSEMBLE = 0;
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__CORE_ASSEMBLE == 0);
		  
		    this->_transition__CORE_ASSEMBLE = 1;
		  }
		
		  return error;
		}
	
		ErrorType port_CORE_DISASSEMBLE() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__CORE_DISASSEMBLE) {
		    case 2:
		      // execute transition of line TO BE DONE
		      assert((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[0/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      _state[1/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("\033[32mBlock %d\033[0m disassembled", this->_param__id);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__CORE_DISASSEMBLE = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__CORE_DISASSEMBLE == 0);
		  
		    this->_transition__CORE_DISASSEMBLE = 2;
		  }
		  
		  this->_transition__CORE_ASSEMBLE = 0;
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__CORE_ASSEMBLE == 0);
		  
		    this->_transition__CORE_ASSEMBLE = 1;
		  }
		
		  return error;
		}
	
		
	
	
	
		void tracename(ostream & out) override {
			out  << "CORE_" << sid << "_" << icount;
		}
	
		void dumpState(ostream & out) override {
		
		}
	
	 };
	unsigned int AT__CORE::icounter = 0;
	
	// --- Begin Parametric Data Objects
	
	// Forward Declarations
	
	class SetAT__CORE;
	
	// Field Accessors
	
	// DATA
	
	// External Ports
	class AT__CORE__transition__CORE_ASSEMBLE {
		public:
			SetAT__CORE* set;
			AT__CORE__transition__CORE_ASSEMBLE(SetAT__CORE* par) { set = par; }
			AT__CORE__transition__CORE_ASSEMBLE & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__CORE__transition__CORE_DISASSEMBLE {
		public:
			SetAT__CORE* set;
			AT__CORE__transition__CORE_DISASSEMBLE(SetAT__CORE* par) { set = par; }
			AT__CORE__transition__CORE_DISASSEMBLE & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	;
	
	// Parametric Containers
	
	class SetAT__CORE {
		public:
			set<AT__CORE*>* elems;
			int size() { assert(elems != NULL); return elems->size(); }
		AT__CORE__transition__CORE_ASSEMBLE _transition__CORE_ASSEMBLE = AT__CORE__transition__CORE_ASSEMBLE(this);
		AT__CORE__transition__CORE_DISASSEMBLE _transition__CORE_DISASSEMBLE = AT__CORE__transition__CORE_DISASSEMBLE(this);
	
	//internal ports 
	ErrorType port_CORE_ASSEMBLE() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_CORE_ASSEMBLE();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_CORE_DISASSEMBLE() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_CORE_DISASSEMBLE();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	};
	
	// Operator Implementation for basic operations
	
	
	AT__CORE__transition__CORE_ASSEMBLE & AT__CORE__transition__CORE_ASSEMBLE::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__CORE_ASSEMBLE = value;
		return *this;
	}
	bool AT__CORE__transition__CORE_ASSEMBLE::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_ASSEMBLE != value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_ASSEMBLE::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_ASSEMBLE == value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_ASSEMBLE::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_ASSEMBLE > value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_ASSEMBLE::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_ASSEMBLE < value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_ASSEMBLE::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_ASSEMBLE <= value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_ASSEMBLE::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_ASSEMBLE >= value)
				return false;
		return true;
	}
	AT__CORE__transition__CORE_DISASSEMBLE & AT__CORE__transition__CORE_DISASSEMBLE::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__CORE_DISASSEMBLE = value;
		return *this;
	}
	bool AT__CORE__transition__CORE_DISASSEMBLE::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_DISASSEMBLE != value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_DISASSEMBLE::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_DISASSEMBLE == value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_DISASSEMBLE::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_DISASSEMBLE > value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_DISASSEMBLE::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_DISASSEMBLE < value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_DISASSEMBLE::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_DISASSEMBLE <= value)
				return false;
		return true;
	}
	bool AT__CORE__transition__CORE_DISASSEMBLE::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CORE_DISASSEMBLE >= value)
				return false;
		return true;
	}
	// --- End Parametric Data Objects
	
	
	
	class AT__SURFACES : public AtomType {
	 public:
		static unsigned int icounter;
		unsigned int sid;
		unsigned int icount;
	
	  // bitvector encoding state
	  unsigned int _state[2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0)];
	
	  // component data
	  bool _m__left;
	  bool _m__right;
	
	
	  // transitions of ports
	  unsigned int _transition__CONNECT_LEFT;
	  unsigned int _transition__DISCONNECT_LEFT;
	  unsigned int _transition__CONNECT_RIGHT;
	  unsigned int _transition__DISCONNECT_RIGHT;
	  unsigned int _transition__CONNECT_CORE;
	;
	
		AT__SURFACES() {
		
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
		ErrorType initialize() override {
			// initialize data of s
			_m__left = false;
			_m__right = false;
			
			// update state of s
			for (unsigned int i = 0 ; i < 2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0) ; ++i) {
			  _state[i] = 0;
			}
			// check for non 1-safety
			if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
			  return NON_ONE_SAFE_PETRI_NET;
			}
			
			_state[0/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
			
			
			
			this->_transition__CONNECT_LEFT = 0;
			
			if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__left))) {
			  assert(this->_transition__CONNECT_LEFT == 0);
			
			  this->_transition__CONNECT_LEFT = 1;
			}
			
			this->_transition__CONNECT_CORE = 0;
			
			if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
			  if (this->_transition__CONNECT_CORE != 0) {
			    return NON_DETERMINISTIC_PETRI_NET;
			  }
			
			  this->_transition__CONNECT_CORE = 6;
			}
			
			if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
			  if (this->_transition__CONNECT_CORE != 0) {
			    return NON_DETERMINISTIC_PETRI_NET;
			  }
			
			  this->_transition__CONNECT_CORE = 5;
			}
			
			this->_transition__CONNECT_RIGHT = 0;
			
			if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__right))) {
			  assert(this->_transition__CONNECT_RIGHT == 0);
			
			  this->_transition__CONNECT_RIGHT = 2;
			}
			
			this->_transition__DISCONNECT_RIGHT = 0;
			
			if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__right)) {
			  assert(this->_transition__DISCONNECT_RIGHT == 0);
			
			  this->_transition__DISCONNECT_RIGHT = 4;
			}
			
			this->_transition__DISCONNECT_LEFT = 0;
			
			if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__left)) {
			  assert(this->_transition__DISCONNECT_LEFT == 0);
			
			  this->_transition__DISCONNECT_LEFT = 3;
			}
	
			return NO_ERROR;
		}
	
	//internal port 
		ErrorType port_CONNECT_LEFT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__CONNECT_LEFT) {
		    case 1:
		      // execute transition of line TO BE DONE
		      assert((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[0/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      _state[1/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("\033[32m[Output]:\033[0m Left has been connected\n");
		      this->_m__left = ! (this->_m__left);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__left))) {
		    assert(this->_transition__CONNECT_LEFT == 0);
		  
		    this->_transition__CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__CONNECT_CORE = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 6;
		  }
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 5;
		  }
		  
		  this->_transition__CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__right))) {
		    assert(this->_transition__CONNECT_RIGHT == 0);
		  
		    this->_transition__CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__right)) {
		    assert(this->_transition__DISCONNECT_RIGHT == 0);
		  
		    this->_transition__DISCONNECT_RIGHT = 4;
		  }
		  
		  this->_transition__DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__left)) {
		    assert(this->_transition__DISCONNECT_LEFT == 0);
		  
		    this->_transition__DISCONNECT_LEFT = 3;
		  }
		
		  return error;
		}
	
		ErrorType port_DISCONNECT_LEFT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__DISCONNECT_LEFT) {
		    case 3:
		      // execute transition of line TO BE DONE
		      assert((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[1/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      _state[0/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("\033[32m[Output]:\033[0m Left has been disconnected\n");
		      this->_m__left = ! (this->_m__left);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__left))) {
		    assert(this->_transition__CONNECT_LEFT == 0);
		  
		    this->_transition__CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__CONNECT_CORE = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 6;
		  }
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 5;
		  }
		  
		  this->_transition__CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__right))) {
		    assert(this->_transition__CONNECT_RIGHT == 0);
		  
		    this->_transition__CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__right)) {
		    assert(this->_transition__DISCONNECT_RIGHT == 0);
		  
		    this->_transition__DISCONNECT_RIGHT = 4;
		  }
		  
		  this->_transition__DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__left)) {
		    assert(this->_transition__DISCONNECT_LEFT == 0);
		  
		    this->_transition__DISCONNECT_LEFT = 3;
		  }
		
		  return error;
		}
	
		ErrorType port_CONNECT_RIGHT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__CONNECT_RIGHT) {
		    case 2:
		      // execute transition of line TO BE DONE
		      assert((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[0/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      _state[1/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("\033[32m[Output]:\033[0m Right has been connected\n");
		      this->_m__right = ! (this->_m__right);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__left))) {
		    assert(this->_transition__CONNECT_LEFT == 0);
		  
		    this->_transition__CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__CONNECT_CORE = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 6;
		  }
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 5;
		  }
		  
		  this->_transition__CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__right))) {
		    assert(this->_transition__CONNECT_RIGHT == 0);
		  
		    this->_transition__CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__right)) {
		    assert(this->_transition__DISCONNECT_RIGHT == 0);
		  
		    this->_transition__DISCONNECT_RIGHT = 4;
		  }
		  
		  this->_transition__DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__left)) {
		    assert(this->_transition__DISCONNECT_LEFT == 0);
		  
		    this->_transition__DISCONNECT_LEFT = 3;
		  }
		
		  return error;
		}
	
		ErrorType port_DISCONNECT_RIGHT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__DISCONNECT_RIGHT) {
		    case 4:
		      // execute transition of line TO BE DONE
		      assert((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[1/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      _state[0/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("\033[32m[Output]:\033[0m Right has been disconnected\n");
		      this->_m__right = ! (this->_m__right);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__left))) {
		    assert(this->_transition__CONNECT_LEFT == 0);
		  
		    this->_transition__CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__CONNECT_CORE = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 6;
		  }
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 5;
		  }
		  
		  this->_transition__CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__right))) {
		    assert(this->_transition__CONNECT_RIGHT == 0);
		  
		    this->_transition__CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__right)) {
		    assert(this->_transition__DISCONNECT_RIGHT == 0);
		  
		    this->_transition__DISCONNECT_RIGHT = 4;
		  }
		  
		  this->_transition__DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__left)) {
		    assert(this->_transition__DISCONNECT_LEFT == 0);
		  
		    this->_transition__DISCONNECT_LEFT = 3;
		  }
		
		  return error;
		}
	
		ErrorType port_CONNECT_CORE() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__CONNECT_CORE) {
		    case 5:
		      // execute transition of line TO BE DONE
		      assert((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[1/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      _state[0/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("\033[32m[Output]:\033[0m Surfaces connected to core\n");
		  
		  
		      break;
		    case 6:
		      // execute transition of line TO BE DONE
		      assert((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[0/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      _state[1/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("\033[32m[Output]:\033[0m Surfaces disconnected to core\n");
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__left))) {
		    assert(this->_transition__CONNECT_LEFT == 0);
		  
		    this->_transition__CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__CONNECT_CORE = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 6;
		  }
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    if (this->_transition__CONNECT_CORE != 0) {
		      return NON_DETERMINISTIC_PETRI_NET;
		    }
		  
		    this->_transition__CONNECT_CORE = 5;
		  }
		  
		  this->_transition__CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (! (this->_m__right))) {
		    assert(this->_transition__CONNECT_RIGHT == 0);
		  
		    this->_transition__CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__right)) {
		    assert(this->_transition__DISCONNECT_RIGHT == 0);
		  
		    this->_transition__DISCONNECT_RIGHT = 4;
		  }
		  
		  this->_transition__DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (this->_m__left)) {
		    assert(this->_transition__DISCONNECT_LEFT == 0);
		  
		    this->_transition__DISCONNECT_LEFT = 3;
		  }
		
		  return error;
		}
	
		
	
	
	
		void tracename(ostream & out) override {
			out  << "SURFACES_" << sid << "_" << icount;
		}
	
		void dumpState(ostream & out) override {
		  out << "_m__left:" << _m__left;
		out << ",";  out << "_m__right:" << _m__right;
		
		}
	
	 };
	unsigned int AT__SURFACES::icounter = 0;
	
	// --- Begin Parametric Data Objects
	
	// Forward Declarations
	
	class SetAT__SURFACES;
	
	// Field Accessors
	
	// DATA
	class AT__SURFACES__m__left {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__m__left(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__m__left & operator=(const bool value);
			bool operator==(const bool value);
			bool operator!=(const bool value);
			bool operator<=(const bool value);
			bool operator>=(const bool value);
			bool operator>(const bool value);
			bool operator<(const bool value);
	};
	class AT__SURFACES__m__right {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__m__right(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__m__right & operator=(const bool value);
			bool operator==(const bool value);
			bool operator!=(const bool value);
			bool operator<=(const bool value);
			bool operator>=(const bool value);
			bool operator>(const bool value);
			bool operator<(const bool value);
	};
	
	// External Ports
	class AT__SURFACES__transition__CONNECT_LEFT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__CONNECT_LEFT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__CONNECT_LEFT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__DISCONNECT_LEFT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__DISCONNECT_LEFT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__DISCONNECT_LEFT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__CONNECT_RIGHT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__CONNECT_RIGHT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__CONNECT_RIGHT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__DISCONNECT_RIGHT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__DISCONNECT_RIGHT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__DISCONNECT_RIGHT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__CONNECT_CORE {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__CONNECT_CORE(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__CONNECT_CORE & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	;
	
	// Parametric Containers
	
	class SetAT__SURFACES {
		public:
			set<AT__SURFACES*>* elems;
			int size() { assert(elems != NULL); return elems->size(); }
	   AT__SURFACES__m__left _m__left = AT__SURFACES__m__left(this);
	   AT__SURFACES__m__right _m__right = AT__SURFACES__m__right(this);
		AT__SURFACES__transition__CONNECT_LEFT _transition__CONNECT_LEFT = AT__SURFACES__transition__CONNECT_LEFT(this);
		AT__SURFACES__transition__DISCONNECT_LEFT _transition__DISCONNECT_LEFT = AT__SURFACES__transition__DISCONNECT_LEFT(this);
		AT__SURFACES__transition__CONNECT_RIGHT _transition__CONNECT_RIGHT = AT__SURFACES__transition__CONNECT_RIGHT(this);
		AT__SURFACES__transition__DISCONNECT_RIGHT _transition__DISCONNECT_RIGHT = AT__SURFACES__transition__DISCONNECT_RIGHT(this);
		AT__SURFACES__transition__CONNECT_CORE _transition__CONNECT_CORE = AT__SURFACES__transition__CONNECT_CORE(this);
	
	//internal ports 
	ErrorType port_CONNECT_LEFT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_CONNECT_LEFT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_DISCONNECT_LEFT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_DISCONNECT_LEFT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_CONNECT_RIGHT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_CONNECT_RIGHT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_DISCONNECT_RIGHT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_DISCONNECT_RIGHT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_CONNECT_CORE() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_CONNECT_CORE();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	};
	
	// Operator Implementation for basic operations
	
	AT__SURFACES__m__left & AT__SURFACES__m__left::operator=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_m__left = value;
		return *this;
	}
	bool AT__SURFACES__m__left::operator==(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__left != value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__left::operator!=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__left == value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__left::operator<=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__left > value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__left::operator>=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__left < value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__left::operator>(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__left <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__left::operator<(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__left >= value)
				return false;
		return true;
	}
	AT__SURFACES__m__right & AT__SURFACES__m__right::operator=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_m__right = value;
		return *this;
	}
	bool AT__SURFACES__m__right::operator==(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__right != value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__right::operator!=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__right == value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__right::operator<=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__right > value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__right::operator>=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__right < value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__right::operator>(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__right <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__right::operator<(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__right >= value)
				return false;
		return true;
	}
	
	AT__SURFACES__transition__CONNECT_LEFT & AT__SURFACES__transition__CONNECT_LEFT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__CONNECT_LEFT = value;
		return *this;
	}
	bool AT__SURFACES__transition__CONNECT_LEFT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_LEFT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_LEFT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_LEFT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_LEFT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_LEFT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_LEFT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_LEFT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_LEFT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_LEFT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_LEFT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_LEFT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__DISCONNECT_LEFT & AT__SURFACES__transition__DISCONNECT_LEFT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__DISCONNECT_LEFT = value;
		return *this;
	}
	bool AT__SURFACES__transition__DISCONNECT_LEFT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_LEFT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_LEFT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_LEFT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_LEFT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_LEFT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_LEFT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_LEFT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_LEFT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_LEFT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_LEFT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_LEFT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__CONNECT_RIGHT & AT__SURFACES__transition__CONNECT_RIGHT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__CONNECT_RIGHT = value;
		return *this;
	}
	bool AT__SURFACES__transition__CONNECT_RIGHT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_RIGHT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_RIGHT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_RIGHT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_RIGHT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_RIGHT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_RIGHT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_RIGHT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_RIGHT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_RIGHT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_RIGHT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_RIGHT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__DISCONNECT_RIGHT & AT__SURFACES__transition__DISCONNECT_RIGHT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__DISCONNECT_RIGHT = value;
		return *this;
	}
	bool AT__SURFACES__transition__DISCONNECT_RIGHT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_RIGHT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_RIGHT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_RIGHT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_RIGHT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_RIGHT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_RIGHT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_RIGHT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_RIGHT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_RIGHT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__DISCONNECT_RIGHT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__DISCONNECT_RIGHT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__CONNECT_CORE & AT__SURFACES__transition__CONNECT_CORE::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__CONNECT_CORE = value;
		return *this;
	}
	bool AT__SURFACES__transition__CONNECT_CORE::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_CORE != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_CORE::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_CORE == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_CORE::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_CORE > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_CORE::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_CORE < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_CORE::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_CORE <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__CONNECT_CORE::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__CONNECT_CORE >= value)
				return false;
		return true;
	}
	// --- End Parametric Data Objects
	




	/*
	 * BIP System
	 */

  class CT__SYS : public BIPSystem {
   public:


    mutable unsigned int interactions;
    mutable unsigned int internals;
    mutable unsigned int externals;
    mutable unsigned int waiting;

	void initialize() override {
		for (auto it= components.begin(); it!=components.end(); ++it)
		    (*it)->initialize();
	}

  };

	/*
	 * Glue
	 */






  // Type encoding for connectors
	class DisconnectCoreAndSurface : public Interaction {
	
	
		public:
		static unsigned int icounter;
		unsigned int icount = 0;
		unsigned int sid = 0;
		
		
		bool enabled = false;
		
		
	
		AT__CORE* _atom_3;
		AT__SURFACES* _atom_4;
	
		DisconnectCoreAndSurface(AT__CORE* _atom_3, AT__SURFACES* _atom_4) {
			assert(_atom_3 != NULL);
			this->_atom_3 = _atom_3;
			assert(_atom_4 != NULL);
			this->_atom_4 = _atom_4;
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
	
		void tracename(ostream & out) override {
			out  << "DisconnectCoreAndSurface_" << sid << "_" << icount;
		}
	
		bool isEnabled() override {
			return enabled;
		}
	
		bool checkSetEnabled() override {
		
	
	
			enabled = ((_atom_4->_transition__CONNECT_CORE != 0)  &&  (_atom_3->_transition__CORE_DISASSEMBLE != 0));
	
	
			return enabled;
		}
		ErrorType execute() {
			ErrorType error = NO_ERROR;
			
			bool _action_1 = (_atom_3->_transition__CORE_DISASSEMBLE != 0);
			  bool _action_2 = (_atom_4->_transition__CONNECT_CORE != 0);
			
			  if (_action_1) {
			    // execute ports 'c2.CORE_DISASSEMBLE'
			    error = _atom_3->port_CORE_DISASSEMBLE();
			    
			    if (error != NO_ERROR) {
			      return error;
			    }
			  }
			
			  if (_action_2) {
			    // execute ports 's2.CONNECT_CORE'
			    error = _atom_4->port_CONNECT_CORE();
			    
			    if (error != NO_ERROR) {
			      return error;
			    }
			  }
	
			return error;
		}
		void print() override {
			if(enabled)
				cout << "(Enabled) ";
	
			cout << this;
	
			cout << " DisconnectCoreAndSurface: ";
	
			cout << _atom_3;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
			cout << ", ";
			cout << _atom_4;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
		}
	};
	unsigned int DisconnectCoreAndSurface::icounter = 0;

	class ConnectCoreAndSurface : public Interaction {
	
	
		public:
		static unsigned int icounter;
		unsigned int icount = 0;
		unsigned int sid = 0;
		
		
		bool enabled = false;
		
		
	
		AT__CORE* _atom_3;
		AT__SURFACES* _atom_4;
	
		ConnectCoreAndSurface(AT__CORE* _atom_3, AT__SURFACES* _atom_4) {
			assert(_atom_3 != NULL);
			this->_atom_3 = _atom_3;
			assert(_atom_4 != NULL);
			this->_atom_4 = _atom_4;
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
	
		void tracename(ostream & out) override {
			out  << "ConnectCoreAndSurface_" << sid << "_" << icount;
		}
	
		bool isEnabled() override {
			return enabled;
		}
	
		bool checkSetEnabled() override {
		
	
	
			enabled = ((_atom_4->_transition__CONNECT_CORE != 0)  &&  (_atom_3->_transition__CORE_ASSEMBLE != 0));
	
	
			return enabled;
		}
		ErrorType execute() {
			ErrorType error = NO_ERROR;
			
			bool _action_1 = (_atom_3->_transition__CORE_ASSEMBLE != 0);
			  bool _action_2 = (_atom_4->_transition__CONNECT_CORE != 0);
			
			  if (_action_1) {
			    // execute ports 'c2.CORE_ASSEMBLE'
			    error = _atom_3->port_CORE_ASSEMBLE();
			    
			    if (error != NO_ERROR) {
			      return error;
			    }
			  }
			
			  if (_action_2) {
			    // execute ports 's2.CONNECT_CORE'
			    error = _atom_4->port_CONNECT_CORE();
			    
			    if (error != NO_ERROR) {
			      return error;
			    }
			  }
	
			return error;
		}
		void print() override {
			if(enabled)
				cout << "(Enabled) ";
	
			cout << this;
	
			cout << " ConnectCoreAndSurface: ";
	
			cout << _atom_3;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
			cout << ", ";
			cout << _atom_4;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
		}
	};
	unsigned int ConnectCoreAndSurface::icounter = 0;

	class Connection : public Interaction {
	
	
		public:
		static unsigned int icounter;
		unsigned int icount = 0;
		unsigned int sid = 0;
		
		
		bool enabled = false;
		
		
	
		AT__SURFACES* _atom_2;
		AT__SURFACES* _atom_4;
	
		Connection(AT__SURFACES* _atom_2, AT__SURFACES* _atom_4) {
			assert(_atom_2 != NULL);
			this->_atom_2 = _atom_2;
			assert(_atom_4 != NULL);
			this->_atom_4 = _atom_4;
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
	
		void tracename(ostream & out) override {
			out  << "Connection_" << sid << "_" << icount;
		}
	
		bool isEnabled() override {
			return enabled;
		}
	
		bool checkSetEnabled() override {
		
	
	
			enabled = ((_atom_2->_transition__CONNECT_RIGHT != 0)  &&  (_atom_4->_transition__CONNECT_LEFT != 0));
	
	
			return enabled;
		}
		ErrorType execute() {
			ErrorType error = NO_ERROR;
			
			bool _action_1 = (_atom_2->_transition__CONNECT_RIGHT != 0);
			  bool _action_2 = (_atom_4->_transition__CONNECT_LEFT != 0);
			
			  if (_action_1) {
			    // execute ports 's.CONNECT_RIGHT'
			    error = _atom_2->port_CONNECT_RIGHT();
			    
			    if (error != NO_ERROR) {
			      return error;
			    }
			  }
			
			  if (_action_2) {
			    // execute ports 's2.CONNECT_LEFT'
			    error = _atom_4->port_CONNECT_LEFT();
			    
			    if (error != NO_ERROR) {
			      return error;
			    }
			  }
	
			return error;
		}
		void print() override {
			if(enabled)
				cout << "(Enabled) ";
	
			cout << this;
	
			cout << " Connection: ";
	
			cout << _atom_2;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
			cout << ", ";
			cout << _atom_4;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
		}
	};
	unsigned int Connection::icounter = 0;



	CT__SYS modelroot;

	void initializeModel() {
		// Set the root pointer to the correct system
		root = (BIPSystem*) &modelroot;

		// Call the initialization of the reconfiguration layer
		reconfigure::init();
	
		// Model imported initialization
		// Uncomment these to execute the initial provided BIP model
		/*
		modelroot.components.push_back(new AT__CORE(1));
		modelroot.components.push_back(new AT__SURFACES());
		modelroot.components.push_back(new AT__CORE(2));
		modelroot.components.push_back(new AT__SURFACES());

		IPool * connectors = poolCreate();

		connectors->insert(
			  	new ConnectCoreAndSurface(
					(AT__CORE*) modelroot.components.at(2)
		, 			(AT__SURFACES*) modelroot.components.at(3)
				)
			);
		connectors->insert(
			  	new Connection(
					(AT__SURFACES*) modelroot.components.at(1)
		, 			(AT__SURFACES*) modelroot.components.at(3)
				)
			);
		connectors->insert(
			  	new Connection(
					(AT__SURFACES*) modelroot.components.at(1)
		, 			(AT__SURFACES*) modelroot.components.at(3)
				)
			);
		connectors->insert(
			  	new ConnectCoreAndSurface(
					(AT__CORE*) modelroot.components.at(0)
		, 			(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new DisconnectCoreAndSurface(
					(AT__CORE*) modelroot.components.at(2)
		, 			(AT__SURFACES*) modelroot.components.at(3)
				)
			);
		connectors->insert(
			  	new DisconnectCoreAndSurface(
					(AT__CORE*) modelroot.components.at(0)
		, 			(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		*/
	}

}

#endif
