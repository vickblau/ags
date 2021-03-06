//=============================================================================
//
// Adventure Game Studio (AGS)
//
// Copyright (C) 1999-2011 Chris Jones and 2011-20xx others
// The full list of copyright holders can be found in the Copyright.txt
// file, which is part of this source code distribution.
//
// The AGS source code is provided under the Artistic License 2.0.
// A copy of this license can be found in the file License.txt and at
// http://www.opensource.org/licenses/artistic-license-2.0.php
//
//=============================================================================

#ifndef __AC_WFNFONTRENDERER_H
#define __AC_WFNFONTRENDERER_H

#include "font/agsfontrenderer.h"
#include "font/wfnfont.h"

#include <map>

class WFNFontRenderer : public IAGSFontRenderer, public IAGSFontRenderer2 {
public:
  virtual bool LoadFromDisk(int fontNumber, int fontSize);
  virtual void FreeMemory(int fontNumber);
  virtual bool SupportsExtendedCharacters(int fontNumber);
  virtual int GetTextWidth(const char *text, int fontNumber);
  virtual int GetTextHeight(const char *text, int fontNumber);
  virtual void RenderText(const char *text, int fontNumber, BITMAP *destination, int x, int y, int colour);
  virtual void AdjustYCoordinateForFont(int *ycoord, int fontNumber);
  virtual void EnsureTextValidForFont(char *text, int fontNumber);

  virtual bool LoadFromDiskEx(int fontNumber, int fontSize, const FontRenderParams *params);

private:
  struct FontData
  {
    WFNFont         *Font;
    FontRenderParams Params;
  };
  std::map<int, FontData> _fontData;
};

#endif // __AC_WFNFONTRENDERER_H
