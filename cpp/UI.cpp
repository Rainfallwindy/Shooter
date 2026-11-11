#include "UI.h"
#include "raylib.h"
void DrawHPBar(int x, int y, int width, int height, Color color) {
	DrawRectangle(x, y, width, height, color);
	DrawRectangle(x, y, width, height, color);
}