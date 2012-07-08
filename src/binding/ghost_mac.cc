#include <node.h>
#include <v8.h>
#include "events_mac.c"
using namespace v8;

v8::Handle<Value> WrappedMouseMove(const Arguments& args) {
  HandleScope scope;
  MouseMove(args[0]->Int32Value(), args[1]->Int32Value());
  return scope.Close(Undefined());
}
v8::Handle<Value> WrappedMouseDownLeft(const Arguments& args) {
  HandleScope scope;
  MouseDownLeft();
  return scope.Close(Undefined());
}
v8::Handle<Value> WrappedMouseDownRight(const Arguments& args) {
  HandleScope scope;
  MouseDownRight();
  return scope.Close(Undefined());
}
v8::Handle<Value> WrappedMouseUpLeft(const Arguments& args) {
  HandleScope scope;
  MouseUpLeft();
  return scope.Close(Undefined());
}
v8::Handle<Value> WrappedMouseUpRight(const Arguments& args) {
  HandleScope scope;
  MouseUpRight();
  return scope.Close(Undefined());
}

v8::Handle<Value> WrappedKeyDown(const Arguments& args) {
  HandleScope scope;
  KeyDown(args[0]->Int32Value());
  return scope.Close(Undefined());
}
v8::Handle<Value> WrappedKeyUp(const Arguments& args) {
  HandleScope scope;
  KeyUp(args[0]->Int32Value());
  return scope.Close(Undefined());
}
v8::Handle<Value> WrappedFromKey(const Arguments& args) {
  HandleScope scope;
  if (args[0]->IsString()) {
    String::AsciiValue ascii(args[0]);
    const char* chars = * ascii;

    if (ascii.length() == 1) {
      return scope.Close(Number::New(KeyCodeFromChar(chars[0])));
    }

    int special = KeyCodeFromSpecial(chars);
    if (special == 0) return scope.Close(v8::Boolean::New(false));
    return scope.Close(Number::New(special));
  }
  return scope.Close(Number::New(KeyCodeFromChar(args[0]->Int32Value())));
}




void init(v8::Handle<Object> target) {
  target->Set(String::NewSymbol("mouseMove"),
      FunctionTemplate::New(WrappedMouseMove)->GetFunction());
  target->Set(String::NewSymbol("mouseDownLeft"),
      FunctionTemplate::New(WrappedMouseDownLeft)->GetFunction());
  target->Set(String::NewSymbol("mouseDownRight"),
      FunctionTemplate::New(WrappedMouseDownRight)->GetFunction());
  target->Set(String::NewSymbol("mouseUpLeft"),
      FunctionTemplate::New(WrappedMouseUpLeft)->GetFunction());
  target->Set(String::NewSymbol("mouseUpRight"),
      FunctionTemplate::New(WrappedMouseUpRight)->GetFunction());

  target->Set(String::NewSymbol("keyDown"),
      FunctionTemplate::New(WrappedKeyDown)->GetFunction());
  target->Set(String::NewSymbol("keyUp"),
      FunctionTemplate::New(WrappedKeyUp)->GetFunction());
  target->Set(String::NewSymbol("fromKey"),
      FunctionTemplate::New(WrappedFromKey)->GetFunction());
}
NODE_MODULE(ghost, init)