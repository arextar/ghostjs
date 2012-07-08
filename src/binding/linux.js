// Curently uses the xte cli, working on getting X11 stuff to compile into a node addon
var spawn = require('child_process').spawn
var xte = spawn('xte', [])
xte.stdin.write('\n')

function command (c) {
  xte.stdin.write(c + '\n')
}

var key_map = {
  home: 'Home',
  left: 'Left',
  up: 'Up',
  right: 'Right',
  down: 'Down',
  pageup: 'Page_Up',
  pagedown: 'Page_Down',
  end: 'End',
  '\n': 'Return',
  enter: 'Return',
  'return': 'Return',
  'back': 'BackSpace',
  backspace: 'BackSpace',
  '\t': 'Tab',
  tab: 'Tab',
  esc: 'Escape',
  del: 'Delete',
  shift: 'Shift_L',
  shiftl: 'Shift_L',
  shiftr: 'Shift_R',
  ctrl: 'Control_L',
  ctrll: 'Control_L',
  ctrlr: 'Control_R',
  meta: 'Meta_L',
  metal: 'Meta_L',
  metar: 'Meta_R',
  alt: 'Alt_L',
  altl: 'Alt_L',
  altr: 'Alt_R'
}

exports.mouseDownLeft = function () {
  command('mousedown 1')
}

exports.mouseDownRight = function () {
  command('mousedown 3')
}

exports.mouseUpLeft = function () {
  command('mouseup 1')
}

exports.mouseUpRight = function () {
  command('mouseup 3')
}

exports.mouseMove = function (x, y) {
  command('mousemove ' + parseInt(x) + ' ' + parseInt(y))
}

exports.mouseMoveRel = function (x, y) {
  command('mousermove ' + parseInt(x) + ' ' + parseInt(y))
}

exports.keyDown = function (k) {
  command('keydown ' + k)
}

exports.keyUp = function (k) {
  command('keyup ' + k)
}

exports.fromKey = function (name) {
  if (key_map.hasOwnProperty(name)) return key_map[name]
  if (typeof name === 'number') return String.fromCharCode(name)
  if (typeof name === 'string' && name.length === 1) return name
  return false
}