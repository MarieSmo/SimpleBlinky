#ifndef BIPMODEL_SimpleBlinky
#define BIPMODEL_SimpleBlinky 1
/*
 * This file contains all types that are specific to the BIP model from which it is generated
 */

// User include given in @cpp annotation
#include <ext.cpp>

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

	
	
	class AT__MCU : public AtomType {
	 public:
		static unsigned int icounter;
		unsigned int sid;
		unsigned int icount;
	
	  // bitvector encoding state
	  unsigned int _state[2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0)];
	
	  // component parameters
	  int _param__id;
	
	  // component data
	  bool _m__MCUSwitcher;
	
	
	  // transitions of ports
	  unsigned int _transition__SWITCH_ON;
	  unsigned int _transition__SWITCH_OFF;
	;
	
		AT__MCU( int   _param__id ) {
			this->_param__id = _param__id;
		
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
		ErrorType initialize() override {
			// update state of m
			for (unsigned int i = 0 ; i < 2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0) ; ++i) {
			  _state[i] = 0;
			}
			// check for non 1-safety
			if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
			  return NON_ONE_SAFE_PETRI_NET;
			}
			
			_state[0/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
			
			
			
			// initial transition of m
			printf("\033[32mBlock %d\033[0m initialise to OFF\n", this->_param__id);
			this->_m__MCUSwitcher = false;
			
			this->_transition__SWITCH_OFF = 0;
			
			if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
			  assert(this->_transition__SWITCH_OFF == 0);
			
			  this->_transition__SWITCH_OFF = 2;
			}
			
			this->_transition__SWITCH_ON = 0;
			
			if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
			  assert(this->_transition__SWITCH_ON == 0);
			
			  this->_transition__SWITCH_ON = 1;
			}
	
			return NO_ERROR;
		}
	
	//internal port 
		ErrorType port_SWITCH_ON() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__SWITCH_ON) {
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
		      this->_m__MCUSwitcher = true;
		      printf("\033[32mBlock %d\033[0m turn on", this->_param__id);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__SWITCH_OFF = 0;
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__SWITCH_OFF == 0);
		  
		    this->_transition__SWITCH_OFF = 2;
		  }
		  
		  this->_transition__SWITCH_ON = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__SWITCH_ON == 0);
		  
		    this->_transition__SWITCH_ON = 1;
		  }
		
		  return error;
		}
	
		ErrorType port_SWITCH_OFF() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__SWITCH_OFF) {
		    case 2:
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
		      this->_m__MCUSwitcher = false;
		      printf("\033[32mBlock %d\033[0m turn off", this->_param__id);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__SWITCH_OFF = 0;
		  
		  if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__SWITCH_OFF == 0);
		  
		    this->_transition__SWITCH_OFF = 2;
		  }
		  
		  this->_transition__SWITCH_ON = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__SWITCH_ON == 0);
		  
		    this->_transition__SWITCH_ON = 1;
		  }
		
		  return error;
		}
	
		
	
	
	
		void tracename(ostream & out) override {
			out  << "MCU_" << sid << "_" << icount;
		}
	
		void dumpState(ostream & out) override {
		  out << "_m__MCUSwitcher:" << _m__MCUSwitcher;
		
		}
	
	 };
	unsigned int AT__MCU::icounter = 0;
	
	// --- Begin Parametric Data Objects
	
	// Forward Declarations
	
	class SetAT__MCU;
	
	// Field Accessors
	
	// DATA
	class AT__MCU__m__MCUSwitcher {
		public:
			SetAT__MCU* set;
			AT__MCU__m__MCUSwitcher(SetAT__MCU* par) { set = par; }
			AT__MCU__m__MCUSwitcher & operator=(const bool value);
			bool operator==(const bool value);
			bool operator!=(const bool value);
			bool operator<=(const bool value);
			bool operator>=(const bool value);
			bool operator>(const bool value);
			bool operator<(const bool value);
	};
	
	// External Ports
	class AT__MCU__transition__SWITCH_ON {
		public:
			SetAT__MCU* set;
			AT__MCU__transition__SWITCH_ON(SetAT__MCU* par) { set = par; }
			AT__MCU__transition__SWITCH_ON & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__MCU__transition__SWITCH_OFF {
		public:
			SetAT__MCU* set;
			AT__MCU__transition__SWITCH_OFF(SetAT__MCU* par) { set = par; }
			AT__MCU__transition__SWITCH_OFF & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	;
	
	// Parametric Containers
	
	class SetAT__MCU {
		public:
			set<AT__MCU*>* elems;
			int size() { assert(elems != NULL); return elems->size(); }
	   AT__MCU__m__MCUSwitcher _m__MCUSwitcher = AT__MCU__m__MCUSwitcher(this);
		AT__MCU__transition__SWITCH_ON _transition__SWITCH_ON = AT__MCU__transition__SWITCH_ON(this);
		AT__MCU__transition__SWITCH_OFF _transition__SWITCH_OFF = AT__MCU__transition__SWITCH_OFF(this);
	
	//internal ports 
	ErrorType port_SWITCH_ON() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_SWITCH_ON();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_SWITCH_OFF() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_SWITCH_OFF();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	};
	
	// Operator Implementation for basic operations
	
	AT__MCU__m__MCUSwitcher & AT__MCU__m__MCUSwitcher::operator=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_m__MCUSwitcher = value;
		return *this;
	}
	bool AT__MCU__m__MCUSwitcher::operator==(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__MCUSwitcher != value)
				return false;
		return true;
	}
	bool AT__MCU__m__MCUSwitcher::operator!=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__MCUSwitcher == value)
				return false;
		return true;
	}
	bool AT__MCU__m__MCUSwitcher::operator<=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__MCUSwitcher > value)
				return false;
		return true;
	}
	bool AT__MCU__m__MCUSwitcher::operator>=(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__MCUSwitcher < value)
				return false;
		return true;
	}
	bool AT__MCU__m__MCUSwitcher::operator>(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__MCUSwitcher <= value)
				return false;
		return true;
	}
	bool AT__MCU__m__MCUSwitcher::operator<(const bool value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__MCUSwitcher >= value)
				return false;
		return true;
	}
	
	AT__MCU__transition__SWITCH_ON & AT__MCU__transition__SWITCH_ON::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__SWITCH_ON = value;
		return *this;
	}
	bool AT__MCU__transition__SWITCH_ON::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_ON != value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_ON::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_ON == value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_ON::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_ON > value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_ON::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_ON < value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_ON::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_ON <= value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_ON::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_ON >= value)
				return false;
		return true;
	}
	AT__MCU__transition__SWITCH_OFF & AT__MCU__transition__SWITCH_OFF::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__SWITCH_OFF = value;
		return *this;
	}
	bool AT__MCU__transition__SWITCH_OFF::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_OFF != value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_OFF::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_OFF == value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_OFF::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_OFF > value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_OFF::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_OFF < value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_OFF::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_OFF <= value)
				return false;
		return true;
	}
	bool AT__MCU__transition__SWITCH_OFF::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SWITCH_OFF >= value)
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
	  int _m__surface_seed;
	  int _m__surface_leaf;
	
	
	  // transitions of ports
	  unsigned int _transition__SEED_CONNECT_LEFT;
	  unsigned int _transition__SEED_CONNECT_RIGHT;
	  unsigned int _transition__SEED_DISCONNECT_RIGHT;
	  unsigned int _transition__SEED_DISCONNECT_LEFT;
	  unsigned int _transition__SEED_LAST_DISCONNECT;
	  unsigned int _transition__LEAF_CONNECT_LEFT;
	  unsigned int _transition__LEAF_CONNECT_RIGHT;
	  unsigned int _transition__LEAF_DISCONNECT_RIGHT;
	  unsigned int _transition__LEAF_DISCONNECT_LEFT;
	;
	
		AT__SURFACES() {
		
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
		ErrorType initialize() override {
			// initialize data of s
			_m__surface_seed = 0;
			_m__surface_leaf = 0;
			
			// update state of s
			for (unsigned int i = 0 ; i < 2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0) ; ++i) {
			  _state[i] = 0;
			}
			// check for non 1-safety
			if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
			  return NON_ONE_SAFE_PETRI_NET;
			}
			
			_state[0/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
			
			
			
			this->_transition__LEAF_DISCONNECT_RIGHT = 0;
			
			if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
			  assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
			
			  this->_transition__LEAF_DISCONNECT_RIGHT = 7;
			}
			
			this->_transition__SEED_LAST_DISCONNECT = 0;
			
			if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
			  assert(this->_transition__SEED_LAST_DISCONNECT == 0);
			
			  this->_transition__SEED_LAST_DISCONNECT = 3;
			}
			
			this->_transition__SEED_CONNECT_LEFT = 0;
			
			if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
			  assert(this->_transition__SEED_CONNECT_LEFT == 0);
			
			  this->_transition__SEED_CONNECT_LEFT = 1;
			}
			
			this->_transition__LEAF_DISCONNECT_LEFT = 0;
			
			if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
			  assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
			
			  this->_transition__LEAF_DISCONNECT_LEFT = 6;
			}
			
			this->_transition__SEED_CONNECT_RIGHT = 0;
			
			if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
			  assert(this->_transition__SEED_CONNECT_RIGHT == 0);
			
			  this->_transition__SEED_CONNECT_RIGHT = 2;
			}
			
			this->_transition__LEAF_CONNECT_LEFT = 0;
			
			if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
			  assert(this->_transition__LEAF_CONNECT_LEFT == 0);
			
			  this->_transition__LEAF_CONNECT_LEFT = 4;
			}
			
			this->_transition__LEAF_CONNECT_RIGHT = 0;
			
			if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
			  assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
			
			  this->_transition__LEAF_CONNECT_RIGHT = 5;
			}
	
			return NO_ERROR;
		}
	
	//internal port 
		ErrorType port_SEED_CONNECT_LEFT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__SEED_CONNECT_LEFT) {
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
		      this->_m__surface_seed = (this->_m__surface_seed)  |  ((1));
		      what_connected(this->_m__surface_seed, this->_m__surface_leaf);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		ErrorType port_SEED_CONNECT_RIGHT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__SEED_CONNECT_RIGHT) {
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
		      this->_m__surface_seed = (this->_m__surface_seed)  |  ((2));
		      what_connected(this->_m__surface_seed, this->_m__surface_leaf);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		ErrorType port_SEED_DISCONNECT_RIGHT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__SEED_DISCONNECT_RIGHT) {
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		ErrorType port_SEED_DISCONNECT_LEFT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__SEED_DISCONNECT_LEFT) {
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		ErrorType port_SEED_LAST_DISCONNECT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__SEED_LAST_DISCONNECT) {
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
		      printf("\033[32m[Output]:\033[0m Last seed has been disconnected\n");
		      this->_m__surface_seed = 0;
		      what_connected(this->_m__surface_seed, this->_m__surface_leaf);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		ErrorType port_LEAF_CONNECT_LEFT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__LEAF_CONNECT_LEFT) {
		    case 4:
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
		      this->_m__surface_leaf = (this->_m__surface_leaf)  |  ((1));
		      what_connected(this->_m__surface_seed, this->_m__surface_leaf);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		ErrorType port_LEAF_CONNECT_RIGHT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__LEAF_CONNECT_RIGHT) {
		    case 5:
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
		      this->_m__surface_leaf = (this->_m__surface_leaf)  |  ((2));
		      what_connected(this->_m__surface_seed, this->_m__surface_leaf);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		ErrorType port_LEAF_DISCONNECT_RIGHT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__LEAF_DISCONNECT_RIGHT) {
		    case 7:
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
		      this->_m__surface_leaf = (this->_m__surface_leaf)  -  ((2));
		      what_connected(this->_m__surface_seed, this->_m__surface_leaf);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		ErrorType port_LEAF_DISCONNECT_LEFT() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__LEAF_DISCONNECT_LEFT) {
		    case 6:
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
		      this->_m__surface_leaf = (this->_m__surface_leaf)  -  ((1));
		      what_connected(this->_m__surface_seed, this->_m__surface_leaf);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__LEAF_DISCONNECT_RIGHT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((2))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_RIGHT = 7;
		  }
		  
		  this->_transition__SEED_LAST_DISCONNECT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && (((this->_m__surface_seed)  ==  (1))  ||  ((this->_m__surface_seed)  ==  (2)))) {
		    assert(this->_transition__SEED_LAST_DISCONNECT == 0);
		  
		    this->_transition__SEED_LAST_DISCONNECT = 3;
		  }
		  
		  this->_transition__SEED_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_LEFT == 0);
		  
		    this->_transition__SEED_CONNECT_LEFT = 1;
		  }
		  
		  this->_transition__LEAF_DISCONNECT_LEFT = 0;
		  
		  if (((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) && ((((1))  &  (this->_m__surface_leaf))  !=  (0))) {
		    assert(this->_transition__LEAF_DISCONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_DISCONNECT_LEFT = 6;
		  }
		  
		  this->_transition__SEED_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__SEED_CONNECT_RIGHT == 0);
		  
		    this->_transition__SEED_CONNECT_RIGHT = 2;
		  }
		  
		  this->_transition__LEAF_CONNECT_LEFT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((1))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((1))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_LEFT == 0);
		  
		    this->_transition__LEAF_CONNECT_LEFT = 4;
		  }
		  
		  this->_transition__LEAF_CONNECT_RIGHT = 0;
		  
		  if (((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) && (((((2))  &  (this->_m__surface_leaf))  ==  (0))  &&  ((((2))  &  (this->_m__surface_seed))  ==  (0)))) {
		    assert(this->_transition__LEAF_CONNECT_RIGHT == 0);
		  
		    this->_transition__LEAF_CONNECT_RIGHT = 5;
		  }
		
		  return error;
		}
	
		
	
	
	
		void tracename(ostream & out) override {
			out  << "SURFACES_" << sid << "_" << icount;
		}
	
		void dumpState(ostream & out) override {
		  out << "_m__surface_seed:" << _m__surface_seed;
		out << ",";  out << "_m__surface_leaf:" << _m__surface_leaf;
		
		}
	
	 };
	unsigned int AT__SURFACES::icounter = 0;
	
	// --- Begin Parametric Data Objects
	
	// Forward Declarations
	
	class SetAT__SURFACES;
	
	// Field Accessors
	
	// DATA
	class AT__SURFACES__m__surface_seed {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__m__surface_seed(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__m__surface_seed & operator=(const int value);
			bool operator==(const int value);
			bool operator!=(const int value);
			bool operator<=(const int value);
			bool operator>=(const int value);
			bool operator>(const int value);
			bool operator<(const int value);
	};
	class AT__SURFACES__m__surface_leaf {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__m__surface_leaf(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__m__surface_leaf & operator=(const int value);
			bool operator==(const int value);
			bool operator!=(const int value);
			bool operator<=(const int value);
			bool operator>=(const int value);
			bool operator>(const int value);
			bool operator<(const int value);
	};
	
	// External Ports
	class AT__SURFACES__transition__SEED_CONNECT_LEFT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__SEED_CONNECT_LEFT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__SEED_CONNECT_LEFT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__SEED_CONNECT_RIGHT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__SEED_CONNECT_RIGHT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__SEED_CONNECT_RIGHT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__SEED_DISCONNECT_RIGHT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__SEED_DISCONNECT_RIGHT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__SEED_DISCONNECT_RIGHT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__SEED_DISCONNECT_LEFT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__SEED_DISCONNECT_LEFT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__SEED_DISCONNECT_LEFT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__SEED_LAST_DISCONNECT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__SEED_LAST_DISCONNECT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__SEED_LAST_DISCONNECT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__LEAF_CONNECT_LEFT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__LEAF_CONNECT_LEFT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__LEAF_CONNECT_LEFT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__LEAF_CONNECT_RIGHT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__LEAF_CONNECT_RIGHT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__LEAF_CONNECT_RIGHT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	class AT__SURFACES__transition__LEAF_DISCONNECT_LEFT {
		public:
			SetAT__SURFACES* set;
			AT__SURFACES__transition__LEAF_DISCONNECT_LEFT(SetAT__SURFACES* par) { set = par; }
			AT__SURFACES__transition__LEAF_DISCONNECT_LEFT & operator=(const unsigned int value);
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
	   AT__SURFACES__m__surface_seed _m__surface_seed = AT__SURFACES__m__surface_seed(this);
	   AT__SURFACES__m__surface_leaf _m__surface_leaf = AT__SURFACES__m__surface_leaf(this);
		AT__SURFACES__transition__SEED_CONNECT_LEFT _transition__SEED_CONNECT_LEFT = AT__SURFACES__transition__SEED_CONNECT_LEFT(this);
		AT__SURFACES__transition__SEED_CONNECT_RIGHT _transition__SEED_CONNECT_RIGHT = AT__SURFACES__transition__SEED_CONNECT_RIGHT(this);
		AT__SURFACES__transition__SEED_DISCONNECT_RIGHT _transition__SEED_DISCONNECT_RIGHT = AT__SURFACES__transition__SEED_DISCONNECT_RIGHT(this);
		AT__SURFACES__transition__SEED_DISCONNECT_LEFT _transition__SEED_DISCONNECT_LEFT = AT__SURFACES__transition__SEED_DISCONNECT_LEFT(this);
		AT__SURFACES__transition__SEED_LAST_DISCONNECT _transition__SEED_LAST_DISCONNECT = AT__SURFACES__transition__SEED_LAST_DISCONNECT(this);
		AT__SURFACES__transition__LEAF_CONNECT_LEFT _transition__LEAF_CONNECT_LEFT = AT__SURFACES__transition__LEAF_CONNECT_LEFT(this);
		AT__SURFACES__transition__LEAF_CONNECT_RIGHT _transition__LEAF_CONNECT_RIGHT = AT__SURFACES__transition__LEAF_CONNECT_RIGHT(this);
		AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT _transition__LEAF_DISCONNECT_RIGHT = AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT(this);
		AT__SURFACES__transition__LEAF_DISCONNECT_LEFT _transition__LEAF_DISCONNECT_LEFT = AT__SURFACES__transition__LEAF_DISCONNECT_LEFT(this);
	
	//internal ports 
	ErrorType port_SEED_CONNECT_LEFT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_SEED_CONNECT_LEFT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_SEED_CONNECT_RIGHT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_SEED_CONNECT_RIGHT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_SEED_DISCONNECT_RIGHT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_SEED_DISCONNECT_RIGHT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_SEED_DISCONNECT_LEFT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_SEED_DISCONNECT_LEFT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_SEED_LAST_DISCONNECT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_SEED_LAST_DISCONNECT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_LEAF_CONNECT_LEFT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_LEAF_CONNECT_LEFT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_LEAF_CONNECT_RIGHT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_LEAF_CONNECT_RIGHT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_LEAF_DISCONNECT_RIGHT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_LEAF_DISCONNECT_RIGHT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	
	ErrorType port_LEAF_DISCONNECT_LEFT() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_LEAF_DISCONNECT_LEFT();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	};
	
	// Operator Implementation for basic operations
	
	AT__SURFACES__m__surface_seed & AT__SURFACES__m__surface_seed::operator=(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_m__surface_seed = value;
		return *this;
	}
	bool AT__SURFACES__m__surface_seed::operator==(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_seed != value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_seed::operator!=(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_seed == value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_seed::operator<=(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_seed > value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_seed::operator>=(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_seed < value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_seed::operator>(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_seed <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_seed::operator<(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_seed >= value)
				return false;
		return true;
	}
	AT__SURFACES__m__surface_leaf & AT__SURFACES__m__surface_leaf::operator=(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_m__surface_leaf = value;
		return *this;
	}
	bool AT__SURFACES__m__surface_leaf::operator==(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_leaf != value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_leaf::operator!=(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_leaf == value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_leaf::operator<=(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_leaf > value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_leaf::operator>=(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_leaf < value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_leaf::operator>(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_leaf <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__m__surface_leaf::operator<(const int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_m__surface_leaf >= value)
				return false;
		return true;
	}
	
	AT__SURFACES__transition__SEED_CONNECT_LEFT & AT__SURFACES__transition__SEED_CONNECT_LEFT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__SEED_CONNECT_LEFT = value;
		return *this;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_LEFT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_LEFT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_LEFT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_LEFT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_LEFT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_LEFT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_LEFT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_LEFT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_LEFT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_LEFT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_LEFT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_LEFT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__SEED_CONNECT_RIGHT & AT__SURFACES__transition__SEED_CONNECT_RIGHT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__SEED_CONNECT_RIGHT = value;
		return *this;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_RIGHT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_RIGHT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_RIGHT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_RIGHT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_RIGHT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_RIGHT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_RIGHT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_RIGHT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_RIGHT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_RIGHT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_CONNECT_RIGHT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_CONNECT_RIGHT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__SEED_DISCONNECT_RIGHT & AT__SURFACES__transition__SEED_DISCONNECT_RIGHT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__SEED_DISCONNECT_RIGHT = value;
		return *this;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_RIGHT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_RIGHT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_RIGHT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_RIGHT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_RIGHT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_RIGHT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_RIGHT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_RIGHT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_RIGHT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_RIGHT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_RIGHT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_RIGHT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__SEED_DISCONNECT_LEFT & AT__SURFACES__transition__SEED_DISCONNECT_LEFT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__SEED_DISCONNECT_LEFT = value;
		return *this;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_LEFT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_LEFT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_LEFT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_LEFT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_LEFT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_LEFT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_LEFT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_LEFT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_LEFT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_LEFT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_DISCONNECT_LEFT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_DISCONNECT_LEFT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__SEED_LAST_DISCONNECT & AT__SURFACES__transition__SEED_LAST_DISCONNECT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__SEED_LAST_DISCONNECT = value;
		return *this;
	}
	bool AT__SURFACES__transition__SEED_LAST_DISCONNECT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_LAST_DISCONNECT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_LAST_DISCONNECT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_LAST_DISCONNECT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_LAST_DISCONNECT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_LAST_DISCONNECT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_LAST_DISCONNECT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_LAST_DISCONNECT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_LAST_DISCONNECT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_LAST_DISCONNECT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__SEED_LAST_DISCONNECT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__SEED_LAST_DISCONNECT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__LEAF_CONNECT_LEFT & AT__SURFACES__transition__LEAF_CONNECT_LEFT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__LEAF_CONNECT_LEFT = value;
		return *this;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_LEFT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_LEFT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_LEFT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_LEFT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_LEFT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_LEFT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_LEFT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_LEFT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_LEFT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_LEFT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_LEFT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_LEFT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__LEAF_CONNECT_RIGHT & AT__SURFACES__transition__LEAF_CONNECT_RIGHT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__LEAF_CONNECT_RIGHT = value;
		return *this;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_RIGHT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_RIGHT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_RIGHT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_RIGHT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_RIGHT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_RIGHT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_RIGHT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_RIGHT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_RIGHT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_RIGHT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_CONNECT_RIGHT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_CONNECT_RIGHT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT & AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__LEAF_DISCONNECT_RIGHT = value;
		return *this;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_RIGHT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_RIGHT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_RIGHT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_RIGHT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_RIGHT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_RIGHT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_RIGHT >= value)
				return false;
		return true;
	}
	AT__SURFACES__transition__LEAF_DISCONNECT_LEFT & AT__SURFACES__transition__LEAF_DISCONNECT_LEFT::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__LEAF_DISCONNECT_LEFT = value;
		return *this;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_LEFT::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_LEFT != value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_LEFT::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_LEFT == value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_LEFT::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_LEFT > value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_LEFT::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_LEFT < value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_LEFT::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_LEFT <= value)
				return false;
		return true;
	}
	bool AT__SURFACES__transition__LEAF_DISCONNECT_LEFT::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__LEAF_DISCONNECT_LEFT >= value)
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
	class switchElementOnOff : public Interaction {
	
	
		public:
		static unsigned int icounter;
		unsigned int icount = 0;
		unsigned int sid = 0;
		
		
		bool enabled = false;
		
		
	
		AT__MCU* _atom_1;
		AT__SURFACES* _atom_2;
	
		switchElementOnOff(AT__MCU* _atom_1, AT__SURFACES* _atom_2) {
			assert(_atom_1 != NULL);
			this->_atom_1 = _atom_1;
			assert(_atom_2 != NULL);
			this->_atom_2 = _atom_2;
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
	
		void tracename(ostream & out) override {
			out  << "switchElementOnOff_" << sid << "_" << icount;
		}
	
		bool isEnabled() override {
			return enabled;
		}
	
		bool checkSetEnabled() override {
		
	
	
			enabled = ((_atom_2->_transition__SEED_CONNECT_LEFT != 0)  &&  (_atom_1->_transition__SWITCH_ON != 0));
	
	
			return enabled;
		}
		ErrorType execute() {
			ErrorType error = NO_ERROR;
			
			bool _action_1 = (_atom_2->_transition__SEED_CONNECT_LEFT != 0);
			  bool _action_2 = (_atom_1->_transition__SWITCH_ON != 0);
			
			  if (_action_1) {
			    // execute ports 's.SEED_CONNECT_LEFT'
			    error = _atom_2->port_SEED_CONNECT_LEFT();
			    
			    if (error != NO_ERROR) {
			      return error;
			    }
			  }
			
			  if (_action_2) {
			    // execute ports 'm.SWITCH_ON'
			    error = _atom_1->port_SWITCH_ON();
			    
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
	
			cout << " switchElementOnOff: ";
	
			cout << _atom_2;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
			cout << ", ";
			cout << _atom_1;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
		}
	};
	unsigned int switchElementOnOff::icounter = 0;

	class InternalConnection : public Interaction {
	
	
		public:
		static unsigned int icounter;
		unsigned int icount = 0;
		unsigned int sid = 0;
		
		
		bool enabled = false;
		
		
	
		AT__SURFACES* _atom_2;
	
		InternalConnection(AT__SURFACES* _atom_2) {
			assert(_atom_2 != NULL);
			this->_atom_2 = _atom_2;
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
	
		void tracename(ostream & out) override {
			out  << "InternalConnection_" << sid << "_" << icount;
		}
	
		bool isEnabled() override {
			return enabled;
		}
	
		bool checkSetEnabled() override {
		
	
	
			enabled = (_atom_2->_transition__SEED_DISCONNECT_RIGHT != 0);
	
	
			return enabled;
		}
		ErrorType execute() {
			ErrorType error = NO_ERROR;
			
			bool _action_1 = (_atom_2->_transition__SEED_DISCONNECT_RIGHT != 0);
			
			  if (_action_1) {
			    // execute ports 's.SEED_DISCONNECT_RIGHT'
			    error = _atom_2->port_SEED_DISCONNECT_RIGHT();
			    
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
	
			cout << " InternalConnection: ";
	
			cout << _atom_2;
			cout << ".";
			cout << "SyncPort";
			cout << "(";
			cout << ")";
		}
	};
	unsigned int InternalConnection::icounter = 0;



	CT__SYS modelroot;

	void initializeModel() {
		// Set the root pointer to the correct system
		root = (BIPSystem*) &modelroot;

		// Call the initialization of the reconfiguration layer
		reconfigure::init();
	
		// Model imported initialization
		// Uncomment these to execute the initial provided BIP model
		/*
		modelroot.components.push_back(new AT__MCU(1));
		modelroot.components.push_back(new AT__SURFACES());

		IPool * connectors = poolCreate();

		connectors->insert(
			  	new InternalConnection(
					(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new InternalConnection(
					(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new InternalConnection(
					(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new switchElementOnOff(
					(AT__MCU*) modelroot.components.at(0)
		, 			(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new InternalConnection(
					(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new switchElementOnOff(
					(AT__MCU*) modelroot.components.at(0)
		, 			(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new InternalConnection(
					(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new switchElementOnOff(
					(AT__MCU*) modelroot.components.at(0)
		, 			(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		connectors->insert(
			  	new InternalConnection(
					(AT__SURFACES*) modelroot.components.at(1)
				)
			);
		*/
	}

}

#endif
