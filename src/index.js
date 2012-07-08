// Load the binding (different places depending on OS until Linux is implemented correctly)
var binding = exports.binding = require('os').type() === 'Linux' ? require('./binding/linux.js') : require('./binding/build/Release/ghost.node')

var key_shift = binding.fromKey('shift')
var key_ctrl = binding.fromKey('ctrl')
var key_alt = binding.fromKey('alt')

// Output a key or array of keys
function key (k) {
  if (Array.isArray(k)) {
    for (var i = 0; i < k.length; i++) {
      key(k[i])
    }
  }
  else
  {
    // If it's a capitalized letter, use the shift key
    var cap = /[A-Z]/.test(k)
    k = binding.fromKey(k.toLowerCase())
    if (cap) binding.keyDown(key_shift)
    binding.keyDown(k)
    binding.keyUp(k)
    if (cap) binding.keyUp(key_shift)
  }
}

exports.key = key

// Type a full string, sending each key seperately
exports.type = function (text) {
  key(text.split(''))
}

exports.keydown = function (k) {
  binding.keyDown(binding.fromKey(k))
}

exports.keyup = function (k) {
  binding.keyUp(binding.fromKey(k))
}

exports.mousemove = function (x, y) {
 binding.mouseMove(x, y)
}

exports.mousemoverel = function (x, y) {
 binding.mouseMoveRel(x, y)
}

// pass true to hold mouse down, false to release mouse held down, or neither to simulate a normal click
exports.leftclick = function (hold) {
  if (hold !== false) binding.mouseDownLeft()
  if (hold !== true) binding.mouseUpLeft()
}

exports.rightclick = function (hold) {
  if (hold !== false) binding.mouseDownRight()
  if (hold !== true) binding.mouseUpRight()
}