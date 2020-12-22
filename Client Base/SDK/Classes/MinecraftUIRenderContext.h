#pragma once

class MinecraftUIRenderContext {
public:
	virtual void Constructor(void);
	virtual float getLineLength(class BitmapFont* font, class TextHolder* text, float textSize, bool unknown);
	virtual float getTextAlpha();
	virtual void setTextAlpha(float alpha);
	virtual __int64 drawDebugText(const float* pos, class TextHolder* text, float* color, float alpha, unsigned int textAlignment, const float* textMeasureData, const void* caretMeasureData);
	virtual __int64 drawText(class BitmapFont* font, struct Vec4* position, class TextHolder* text, MC_Colour colour, float alpha, unsigned int textAlignment, const float* textMeasureData, const uintptr_t* caretMeasureData);
	virtual void flushText(float timeSinceLastFlush);
	virtual __int64 drawImageNOTIMPLEMENTED();
	virtual __int64 drawNinesliceNOTIMPLEMENTED();
	virtual __int64 flushImagesNOTIMPLEMENTED();
	virtual __int64 beginSharedMeshBatchNOTIMPLEMENTED();
	virtual __int64 endSharedMeshBatchNOTIMPLEMENTED();
	virtual void drawRectangle(struct Vec4 position, MC_Colour colour, float alpha, int lineWidth);
	virtual void fillRectangle(struct Vec4 position, MC_Colour colour, float alpha);
};