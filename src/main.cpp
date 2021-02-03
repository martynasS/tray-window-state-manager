#include <node.h>
#include <v8.h>
#include <windows.h>

using v8::FunctionCallbackInfo;
using v8::Local;
using v8::Object;
using v8::Value;

void TogglePopup(const FunctionCallbackInfo<Value>& args) {
  HWND overflow = FindWindow("NotifyIconOverflowWindow", NULL);
  
  if (overflow != NULL && IsWindowVisible(overflow)) {
    ShowWindow(overflow, SW_HIDE);
  } else {
    ShowWindow(overflow, SW_SHOWNORMAL);
  }
}

void ShowPopup(const FunctionCallbackInfo<Value>& args) {
  HWND overflow = FindWindow("NotifyIconOverflowWindow", NULL);
  
  if (overflow != NULL && !IsWindowVisible(overflow)) {
    ShowWindow(overflow, SW_SHOWNORMAL);
  }
}

void HidePopup(const FunctionCallbackInfo<Value>& args) {
  HWND overflow = FindWindow("NotifyIconOverflowWindow", NULL);
  
  if (overflow != NULL && IsWindowVisible(overflow)) {
    ShowWindow(overflow, SW_HIDE);
  }
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "togglePopup", TogglePopup);
  NODE_SET_METHOD(exports, "showPopup", ShowPopup);
  NODE_SET_METHOD(exports, "hidePopup", HidePopup);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)
