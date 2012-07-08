#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>
#include <stdio.h>

#define KEY_FROM_QWERTY_BODY(cc) \
	((cc == ' ') ? 0x31 : \
	((cc == ',') ? 0x2B : \
	((cc == '-') ? 0x1B : \
	((cc == '.') ? 0x2F : \
	((cc == '/') ? 0x2C : \
	((cc == '0') ? 0x1D : \
	((cc == '1') ? 0x12 : \
	((cc == '2') ? 0x13 : \
	((cc == '3') ? 0x14 : \
	((cc == '4') ? 0x15 : \
	((cc == '5') ? 0x17 : \
	((cc == '6') ? 0x16 : \
	((cc == '7') ? 0x1A : \
	((cc == '8') ? 0x1C : \
	((cc == '9') ? 0x19 : \
	((cc == ';') ? 0x29 : \
	((cc == '=') ? 0x18 : \
	((cc == 'A') ? 0x00 : \
	((cc == 'B') ? 0x0B : \
	((cc == 'C') ? 0x08 : \
	((cc == 'D') ? 0x02 : \
	((cc == 'E') ? 0x0E : \
	((cc == 'F') ? 0x03 : \
	((cc == 'G') ? 0x05 : \
	((cc == 'H') ? 0x04 : \
	((cc == 'I') ? 0x22 : \
	((cc == 'J') ? 0x26 : \
	((cc == 'K') ? 0x28 : \
	((cc == 'L') ? 0x25 : \
	((cc == 'M') ? 0x2E : \
	((cc == 'N') ? 0x2D : \
	((cc == 'O') ? 0x1F : \
	((cc == 'P') ? 0x23 : \
	((cc == 'Q') ? 0x0C : \
	((cc == 'R') ? 0x0F : \
	((cc == 'S') ? 0x01 : \
	((cc == 'T') ? 0x11 : \
	((cc == 'U') ? 0x20 : \
	((cc == 'V') ? 0x09 : \
	((cc == 'W') ? 0x0D : \
	((cc == 'X') ? 0x07 : \
	((cc == 'Y') ? 0x10 : \
	((cc == 'Z') ? 0x06 : \
	((cc == '[') ? 0x21 : \
	((cc == '\'') ? 0x27 : \
	((cc == '\\') ? 0x2A : \
	((cc == '\b') ? 0x33 : \
	((cc == '\f') ? 0x79 : \
	((cc == '\r') ? 0x24 : \
	((cc == '\t') ? 0x30 : \
	((cc == '\v') ? 0x74 : \
	((cc == '\x01') ? 0x73 : \
	((cc == '\x03') ? 0x4C : \
	((cc == '\x04') ? 0x77 : \
	((cc == '\x05') ? 0x72 : \
	((cc == '\x1B') ? 0x47 : \
	((cc == '\x1C') ? 0x7B : \
	((cc == '\x1D') ? 0x7C : \
	((cc == '\x1E') ? 0x7E : \
	((cc == '\x1F') ? 0x7D : \
	((cc == '\x7F') ? 0x75 : \
	((cc == ']') ? 0x1E : \
	((cc == '`') ? 0x32 : \
	((cc == 'a') ? 0x00 : \
	((cc == 'b') ? 0x0B : \
	((cc == 'c') ? 0x08 : \
	((cc == 'd') ? 0x02 : \
	((cc == 'e') ? 0x0E : \
	((cc == 'f') ? 0x03 : \
	((cc == 'g') ? 0x05 : \
	((cc == 'h') ? 0x04 : \
	((cc == 'i') ? 0x22 : \
	((cc == 'j') ? 0x26 : \
	((cc == 'k') ? 0x28 : \
	((cc == 'l') ? 0x25 : \
	((cc == 'm') ? 0x2E : \
	((cc == 'n') ? 0x2D : \
	((cc == 'o') ? 0x1F : \
	((cc == 'p') ? 0x23 : \
	((cc == 'q') ? 0x0C : \
	((cc == 'r') ? 0x0F : \
	((cc == 's') ? 0x01 : \
	((cc == 't') ? 0x11 : \
	((cc == 'u') ? 0x20 : \
	((cc == 'v') ? 0x09 : \
	((cc == 'w') ? 0x0D : \
	((cc == 'x') ? 0x07 : \
	((cc == 'y') ? 0x10 : \
	((cc == 'z') ? 0x06 : \
	0 \
	))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))\
	)))))))))))))))))

CGPoint MousePos () {
	CGEventRef ourEvent = CGEventCreate(NULL);
	return CGEventGetLocation(ourEvent); 
}

extern "C" {

	void MouseDownLeft () {
		CGEventRef mouse_down = CGEventCreateMouseEvent(
	        NULL, kCGEventLeftMouseDown,
	        MousePos(),
	        kCGMouseButtonLeft
	    );
	    CGEventPost(kCGHIDEventTap, mouse_down);
	    CFRelease(mouse_down);
	}

	void MouseDownRight () {
		CGEventRef mouse_down = CGEventCreateMouseEvent(
	        NULL, kCGEventRightMouseDown,
	        MousePos(),
	        kCGMouseButtonLeft
	    );
	    CGEventPost(kCGHIDEventTap, mouse_down);
	    CFRelease(mouse_down);
	}

	void MouseUpLeft () {
		CGEventRef mouse_down = CGEventCreateMouseEvent(
	        NULL, kCGEventLeftMouseUp,
	        MousePos(),
	        kCGMouseButtonLeft
	    );
	    CGEventPost(kCGHIDEventTap, mouse_down);
	    CFRelease(mouse_down);
	}

	void MouseUpRight () {
		CGEventRef mouse_down = CGEventCreateMouseEvent(
	        NULL, kCGEventRightMouseUp,
	        MousePos(),
	        kCGMouseButtonLeft
	    );
	    CGEventPost(kCGHIDEventTap, mouse_down);
	    CFRelease(mouse_down);
	}

	void MouseMove (int x, int y) {
		CGEventRef move = CGEventCreateMouseEvent(
	        NULL, kCGEventMouseMoved,
	        CGPointMake(x, y),
	        kCGMouseButtonLeft // ignored
	    );
	    CGEventPost(kCGHIDEventTap, move);
	    CFRelease(move);
	}

	void KeyDown (int keyCode) {
		CGEventRef event = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)keyCode, true);
		CGEventPost(kCGHIDEventTap, event);
		CFRelease(event);
	}

	void KeyUp (int keyCode) {
		CGEventRef event = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)keyCode, false);
		CGEventPost(kCGHIDEventTap, event);
		CFRelease(event);
	}

	int KeyCodeFromChar (char c) {
		return KEY_FROM_QWERTY_BODY(c);
	}

	int KeyCodeFromSpecial (const char* c) {
		if (strcmp(c, "shift") == 0) return 56;
		return 0;
	}
}

int main() {
    return 0;
}