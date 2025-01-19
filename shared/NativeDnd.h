#pragma once

#include <AppSpecsJSI.h>

#include <memory>
#include <string>

namespace facebook::react {

class NativeDnd : public NativeDndCxxSpec<NativeDnd> {
public:
  NativeDnd(std::shared_ptr<CallInvoker> jsInvoker);

  std::string dndFun(jsi::Runtime& rt, std::string input);
};

} // namespace facebook::react
