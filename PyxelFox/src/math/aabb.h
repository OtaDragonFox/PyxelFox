#pragma once
#include "math.h"

static bool boxOverlap(vec2 aStart, vec2 aEnd, vec2 bStart, vec2 bEnd)
{




}

static bool cursorOverlap(vec2 aTopLeft, vec2 aBottomRight, vec2 cursortLoc)
{
	if (aTopLeft.x < cursortLoc.x && aBottomRight.x > cursortLoc.x)
		return true;

	return false;
}