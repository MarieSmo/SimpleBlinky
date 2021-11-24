#ifndef _AtomExternalPort_HPP_
#define _AtomExternalPort_HPP_

#include <signal.h>
#include <string>

using namespace std;

namespace bipscheduler {
  extern pid_t pid;
};

namespace Engine {
  extern const int SIGBIP;
};

enum EventConsumptionPolicy {
  REMEMBER = 0,
  IGNORE = 1,
  ERROR = 2
};

class AtomExternalPort {
 public:
  // constructor
  AtomExternalPort(const string &name, const EventConsumptionPolicy &policy) :
    mName(name),
    mPolicy(policy),
    mIsEnabled(false) {
  }

  // destructor
  virtual ~AtomExternalPort() { }
  
  // getters / setters
  EventConsumptionPolicy policy() const { return mPolicy; }
  void setIsEnabled(bool b) { mIsEnabled = b; }
  bool isEnabled() const { return mIsEnabled; }

  // operations
  virtual void notify() { kill(bipscheduler::pid, Engine::SIGBIP); }
  virtual void initialize() = 0;
  virtual bool hasEvent() const = 0;
  virtual void popEvent() = 0;
  virtual void purgeEvents() = 0;

 private:
  // attributes
  const string mName;
  const EventConsumptionPolicy mPolicy;
  bool mIsEnabled;
};

#endif // _AtomExternalPort_HPP_
