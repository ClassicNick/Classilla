/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: NPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is 
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or 
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the NPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the NPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
#ifndef nsGfxCheckboxControlFrame_h___
#define nsGfxCheckboxControlFrame_h___

#include "nsFormControlFrame.h"
#include "nsICheckboxControlFrame.h"

#ifdef ACCESSIBILITY
class nsIAccessible;
#endif


#define NS_GFX_CHECKBOX_CONTROL_FRAME_FACE_CONTEXT_INDEX   0 // for additional style contexts
#define NS_GFX_CHECKBOX_CONTROL_FRAME_LAST_CONTEXT_INDEX   0

class nsGfxCheckboxControlFrame : public nsFormControlFrame,
                                  public nsICheckboxControlFrame//,
                                  //public nsIAccessible
{
public:

  //NS_DECL_NSIACCESSIBLE

  nsGfxCheckboxControlFrame();
  virtual ~nsGfxCheckboxControlFrame();
  
#ifdef DEBUG
  NS_IMETHOD GetFrameName(nsAString& aResult) const {
    return MakeFrameName(NS_LITERAL_STRING("CheckboxControl"), aResult);
  }
#endif

  NS_IMETHOD Paint(nsIPresContext*      aPresContext,
                   nsIRenderingContext& aRenderingContext,
                   const nsRect&        aDirtyRect,
                   nsFramePaintLayer    aWhichLayer,
                   PRUint32             aFlags = 0);

#ifdef ACCESSIBILITY
  NS_IMETHOD GetAccessible(nsIAccessible** aAccessible);
#endif


  //nsICheckboxControlFrame methods
  NS_IMETHOD SetCheckboxFaceStyleContext(nsIStyleContext *aCheckboxFaceStyleContext);
  NS_IMETHOD OnChecked(nsIPresContext* aPresContext, PRBool aChecked);

  NS_IMETHOD GetAdditionalStyleContext(PRInt32 aIndex, 
                                       nsIStyleContext** aStyleContext) const;
  NS_IMETHOD SetAdditionalStyleContext(PRInt32 aIndex, 
                                       nsIStyleContext* aStyleContext);

    // nsIFormControlFrame
  NS_IMETHOD OnContentReset();

  NS_IMETHOD QueryInterface(const nsIID& aIID, void** aInstancePtr);

#ifdef DEBUG_rodsXXX
  NS_IMETHOD Reflow(nsIPresContext*          aCX,
                    nsHTMLReflowMetrics&     aDesiredSize,
                    const nsHTMLReflowState& aReflowState,
                    nsReflowStatus&          aStatus);
#endif

protected:

  PRBool GetCheckboxState();

protected:

  virtual void PaintCheckBox(nsIPresContext* aPresContext,
                             nsIRenderingContext& aRenderingContext,
                             const nsRect& aDirtyRect,
                             nsFramePaintLayer aWhichLayer);

  //GFX-rendered state variables
  PRBool           mInClickEvent;
  nsIStyleContext* mCheckButtonFaceStyle;

private:
  NS_IMETHOD_(nsrefcnt) AddRef() { return NS_OK; }
  NS_IMETHOD_(nsrefcnt) Release() { return NS_OK; }
 
};

#endif
