//
// UIColor+RBExtras.h
//
// Copyright (c) 2011 Robert Brown
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <UIKit/UIKit.h>

@interface UIColor (RBExtras)

/// @return A random color with alpha of 1.0.
+ (UIColor *)randomColor;

/// @return A random color with random alpha.
+ (UIColor *)randomColorAndAlpha;

// Colors found in the Mac crayon box color picker.

+ (UIColor *)aluminumCrayonColor;
+ (UIColor *)aquaCrayonColor;
+ (UIColor *)asparagusCrayonColor;
+ (UIColor *)bananaCrayonColor;
+ (UIColor *)blueberryCrayonColor;
+ (UIColor *)bubblegumCrayonColor;
+ (UIColor *)carnationCrayonColor;
+ (UIColor *)cantalopeCrayonColor;
+ (UIColor *)cayenneCrayonColor;
+ (UIColor *)cloverCrayonColor;
+ (UIColor *)eggplantCrayonColor;
+ (UIColor *)fernCrayonColor;
+ (UIColor *)floraCrayonColor;
+ (UIColor *)grapeCrayonColor;
+ (UIColor *)honeydewCrayonColor;
+ (UIColor *)iceCrayonColor;
+ (UIColor *)ironCrayonColor;
+ (UIColor *)lavenderCrayonColor;
+ (UIColor *)leadCrayonColor;
+ (UIColor *)lemonCrayonColor;
+ (UIColor *)licoriceCrayonColor;
+ (UIColor *)limeCrayonColor;
+ (UIColor *)magentaCrayonColor;
+ (UIColor *)magnesiumCrayonColor;
+ (UIColor *)maraschinoCrayonColor;
+ (UIColor *)maroonCrayonColor;
+ (UIColor *)mercuryCrayonColor;
+ (UIColor *)midnightCrayonColor;
+ (UIColor *)mochaCrayonColor;
+ (UIColor *)mossCrayonColor;
+ (UIColor *)nickelCrayonColor;
+ (UIColor *)oceanCrayonColor;
+ (UIColor *)orchidCrayonColor;
+ (UIColor *)plumCrayonColor;
+ (UIColor *)salmonCrayonColor;
+ (UIColor *)seafoamCrayonColor;
+ (UIColor *)silverCrayonColor;
+ (UIColor *)skyCrayonColor;
+ (UIColor *)snowCrayonColor;
+ (UIColor *)spindriftCrayonColor;
+ (UIColor *)springCrayonColor;
+ (UIColor *)steelCrayonColor;
+ (UIColor *)strawberryCrayonColor;
+ (UIColor *)tangerineCrayonColor;
+ (UIColor *)tealCrayonColor;
+ (UIColor *)tinCrayonColor;
+ (UIColor *)tungstenCrayonColor;
+ (UIColor *)turquoiseCrayonColor;

// Standard HTML colors

+ (UIColor *)aliceBlueHTMLColor;
+ (UIColor *)antiqueWhiteHTMLColor;
+ (UIColor *)aquaHTMLColor;
+ (UIColor *)aquamarineHTMLColor;
+ (UIColor *)azureHTMLColor;
+ (UIColor *)beigeHTMLColor;
+ (UIColor *)bisqueHTMLColor;
+ (UIColor *)blackHTMLColor;
+ (UIColor *)blanchedAlmondHTMLColor;
+ (UIColor *)blueHTMLColor;
+ (UIColor *)blueVioletHTMLColor;
+ (UIColor *)brownHTMLColor;
+ (UIColor *)burlyWoodHTMLColor;
+ (UIColor *)cadetBlueHTMLColor;
+ (UIColor *)chartreuseHTMLColor;
+ (UIColor *)chocolateHTMLColor;
+ (UIColor *)coralHTMLColor;
+ (UIColor *)cornflowerBlueHTMLColor;
+ (UIColor *)cornsilkHTMLColor;
+ (UIColor *)crimsonHTMLColor;
+ (UIColor *)cyanHTMLColor;
+ (UIColor *)darkBlueHTMLColor;
+ (UIColor *)darkCyanHTMLColor;
+ (UIColor *)darkGoldenRodHTMLColor;
+ (UIColor *)darkGrayHTMLColor;
+ (UIColor *)darkGreyHTMLColor;
+ (UIColor *)darkGreenHTMLColor;
+ (UIColor *)darkKhakiHTMLColor;
+ (UIColor *)darkMagentaHTMLColor;
+ (UIColor *)darkOliveGreenHTMLColor;
+ (UIColor *)darkorangeHTMLColor;
+ (UIColor *)darkOrchidHTMLColor;
+ (UIColor *)darkRedHTMLColor;
+ (UIColor *)darkSalmonHTMLColor;
+ (UIColor *)darkSeaGreenHTMLColor;
+ (UIColor *)darkSlateBlueHTMLColor;
+ (UIColor *)darkSlateGrayHTMLColor;
+ (UIColor *)darkSlateGreyHTMLColor;
+ (UIColor *)darkTurquoiseHTMLColor;
+ (UIColor *)darkVioletHTMLColor;
+ (UIColor *)deepPinkHTMLColor;
+ (UIColor *)deepSkyBlueHTMLColor;
+ (UIColor *)dimGrayHTMLColor;
+ (UIColor *)dimGreyHTMLColor;
+ (UIColor *)dodgerBlueHTMLColor;
+ (UIColor *)fireBrickHTMLColor;
+ (UIColor *)floralWhiteHTMLColor;
+ (UIColor *)forestGreenHTMLColor;
+ (UIColor *)fuchsiaHTMLColor;
+ (UIColor *)gainsboroHTMLColor;
+ (UIColor *)ghostWhiteHTMLColor;
+ (UIColor *)goldHTMLColor;
+ (UIColor *)goldenRodHTMLColor;
+ (UIColor *)grayHTMLColor;
+ (UIColor *)greyHTMLColor;
+ (UIColor *)greenHTMLColor;
+ (UIColor *)greenYellowHTMLColor;
+ (UIColor *)honeyDewHTMLColor;
+ (UIColor *)hotPinkHTMLColor;
+ (UIColor *)indianRedHTMLColor;
+ (UIColor *)indigoHTMLColor;
+ (UIColor *)ivoryHTMLColor;
+ (UIColor *)khakiHTMLColor;
+ (UIColor *)lavenderHTMLColor;
+ (UIColor *)lavenderBlushHTMLColor;
+ (UIColor *)lawnGreenHTMLColor;
+ (UIColor *)lemonChiffonHTMLColor;
+ (UIColor *)lightBlueHTMLColor;
+ (UIColor *)lightCoralHTMLColor;
+ (UIColor *)lightCyanHTMLColor;
+ (UIColor *)lightGoldenRodYellowHTMLColor;
+ (UIColor *)lightGrayHTMLColor;
+ (UIColor *)lightGreyHTMLColor;
+ (UIColor *)lightGreenHTMLColor;
+ (UIColor *)lightPinkHTMLColor;
+ (UIColor *)lightSalmonHTMLColor;
+ (UIColor *)lightSeaGreenHTMLColor;
+ (UIColor *)lightSkyBlueHTMLColor;
+ (UIColor *)lightSlateGrayHTMLColor;
+ (UIColor *)lightSlateGreyHTMLColor;
+ (UIColor *)lightSteelBlueHTMLColor;
+ (UIColor *)lightYellowHTMLColor;
+ (UIColor *)limeHTMLColor;
+ (UIColor *)limeGreenHTMLColor;
+ (UIColor *)linenHTMLColor;
+ (UIColor *)magentaHTMLColor;
+ (UIColor *)maroonHTMLColor;
+ (UIColor *)mediumAquaMarineHTMLColor;
+ (UIColor *)mediumBlueHTMLColor;
+ (UIColor *)mediumOrchidHTMLColor;
+ (UIColor *)mediumPurpleHTMLColor;
+ (UIColor *)mediumSeaGreenHTMLColor;
+ (UIColor *)mediumSlateBlueHTMLColor;
+ (UIColor *)mediumSpringGreenHTMLColor;
+ (UIColor *)mediumTurquoiseHTMLColor;
+ (UIColor *)mediumVioletRedHTMLColor;
+ (UIColor *)midnightBlueHTMLColor;
+ (UIColor *)mintCreamHTMLColor;
+ (UIColor *)mistyRoseHTMLColor;
+ (UIColor *)moccasinHTMLColor;
+ (UIColor *)navajoWhiteHTMLColor;
+ (UIColor *)navyHTMLColor;
+ (UIColor *)oldLaceHTMLColor;
+ (UIColor *)oliveHTMLColor;
+ (UIColor *)oliveDrabHTMLColor;
+ (UIColor *)orangeHTMLColor;
+ (UIColor *)orangeRedHTMLColor;
+ (UIColor *)orchidHTMLColor;
+ (UIColor *)paleGoldenRodHTMLColor;
+ (UIColor *)paleGreenHTMLColor;
+ (UIColor *)paleTurquoiseHTMLColor;
+ (UIColor *)paleVioletRedHTMLColor;
+ (UIColor *)papayaWhipHTMLColor;
+ (UIColor *)peachPuffHTMLColor;
+ (UIColor *)peruHTMLColor;
+ (UIColor *)pinkHTMLColor;
+ (UIColor *)plumHTMLColor;
+ (UIColor *)powderBlueHTMLColor;
+ (UIColor *)purpleHTMLColor;
+ (UIColor *)redHTMLColor;
+ (UIColor *)rosyBrownHTMLColor;
+ (UIColor *)royalBlueHTMLColor;
+ (UIColor *)saddleBrownHTMLColor;
+ (UIColor *)salmonHTMLColor;
+ (UIColor *)sandyBrownHTMLColor;
+ (UIColor *)seaGreenHTMLColor;
+ (UIColor *)seaShellHTMLColor;
+ (UIColor *)siennaHTMLColor;
+ (UIColor *)silverHTMLColor;
+ (UIColor *)skyBlueHTMLColor;
+ (UIColor *)slateBlueHTMLColor;
+ (UIColor *)slateGrayHTMLColor;
+ (UIColor *)slateGreyHTMLColor;
+ (UIColor *)snowHTMLColor;
+ (UIColor *)springGreenHTMLColor;
+ (UIColor *)steelBlueHTMLColor;
+ (UIColor *)tanHTMLColor;
+ (UIColor *)tealHTMLColor;
+ (UIColor *)thistleHTMLColor;
+ (UIColor *)tomatoHTMLColor;
+ (UIColor *)turquoiseHTMLColor;
+ (UIColor *)violetHTMLColor;
+ (UIColor *)wheatHTMLColor;
+ (UIColor *)whiteHTMLColor;
+ (UIColor *)whiteSmokeHTMLColor;
+ (UIColor *)yellowHTMLColor;
+ (UIColor *)yellowGreenHTMLColor;

@end
