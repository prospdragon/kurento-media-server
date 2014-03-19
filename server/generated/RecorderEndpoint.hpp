/* Autogenerated with Kurento Idl */

#ifndef __RECORDER_ENDPOINT_HPP__
#define __RECORDER_ENDPOINT_HPP__

#include <jsoncpp/json/json.h>
#include <JsonRpcException.hpp>
#include <ObjectRegistrar.hpp>
#include <memory>
#include <vector>
#include "UriEndpoint.hpp"

namespace kurento {

class MediaPipeline;
class MediaProfileSpecType;

class RecorderEndpoint : public virtual UriEndpoint {

public:

  RecorderEndpoint () {};
  virtual ~RecorderEndpoint () {};

  virtual void record () {throw "Not implemented";};

  virtual std::string connect(const std::string &eventType, std::shared_ptr<EventHandler> handler);

  class Factory : public virtual kurento::Factory
  {
  public:
    Factory () {};

    virtual std::string getName () {
      return "RecorderEndpoint";
    };

  private:

    virtual MediaObject * createObjectPointer (const Json::Value &params);

    MediaObject * createObject (std::shared_ptr<MediaPipeline> mediaPipeline, const std::string& uri, std::shared_ptr<MediaProfileSpecType> mediaProfile, bool stopOnEndOfStream, int garbagePeriod);

    class StaticConstructor
    {
    public:
      StaticConstructor();
    };

    static StaticConstructor staticConstructor;

  };

  class Invoker : public virtual UriEndpoint::Invoker
  {
  public:
    Invoker() {};
    virtual void invoke (std::shared_ptr<MediaObject> obj,
        const std::string &methodName, const Json::Value &params,
        Json::Value &response);
  };

  virtual MediaObject::Invoker &getInvoker() {
    return invoker;
  }

  private:
    Invoker invoker;

};

} /* kurento */

#endif /*  __RECORDER_ENDPOINT_HPP__ */