#include "type.h"

#define edip_COM /*s_COM/*0

//sends *buf as a data packet
BYTE edip_small_packet(BYTE *buf, BYTE len);
//retreives the screen's buffer
BYTE *edip_small_buffer();

//sends a command packet
BYTE edip_packet(BYTE *str, BYTE len, ...);

#define _0(str)		edip_packet(str, 0)
#define _1(str, a)	edip_packet(str, 1, a)
#define _color(str)	edip_packet(str, 2, fg, bg)
#define _zoom(str)	edip_packet(str, 2, x_z, y_z)

#define edip_FF()	edip_small_packet("\f",1)
#define edip_CR()	edip_small_packet("\r",1)
#define edip_LF()	edip_small_packet("\n",1)

#define edip_term(enable)					_0(enable?"FE":"FA")
#define edip_termColor(fg, bg)				_color("FT")
#define edip_termWindow(font, C, L, W, H)	edip_packet("TW", 5, font, C, L, W, H)

#define edip_cursor(enable)		_1("TC", enable)
#define edip_cursorPos(C, L)	edip_packet("TP", 2, C, L)
#define edip_cursorSave()		_0("TS")
#define edip_cursorLoad()		_0("TR")

#define edip_printVersion()		_0("TV")
#define edip_printProject()		_0("TJ")
#define edip_printIface()		_0("TQ")
#define edip_printInfo()		_0("TI")
extern void edip_printOrient(BYTE o, POINT at, BYTE *str);	// "Z$o" _pt(at) str...
extern void edip_printArea(POINT from, POINT to, BYTE *str); // "ZB" _pt(from) _pt(to) str...
extern void edip_printTerm(BYTE *str); // "ZT" str...

#define edip_dispColor(fg, bg)	_color("FD")
#define edip_dispOrient(o)		_1("DO", o)
#define edip_dispBG()			_0("DL")
#define edip_dispFG()			_0("DS")
#define edip_dispFill(C)		_1("DF", C)
#define edip_dispInvert()		_0("DI")

#define edip_font(font)			_1("ZF", font)
#define edip_fontColor(fg, bg)	_color("FZ")
#define edip_fontZoom(x_z, y_z)	_zoom("ZZ")
#define edip_fontZoom2(x_z,y_z)	_zoom("ZY")
#define edip_fontSpace(dot)		_1("ZJ", dot)
#define edip_fontOrient(o)		_1("ZW", o)

#define _co(word)		(word & 0xFF), ((word >> 8) & 0xFF)
#define _pt(pt)			_co(pt.x), _co(pt.y)
#define _1d(str, pt)	edip_packet(str, 4, _pt(pt)
#define _2d(str)		edip_packet(str, 8, _pt(from), _pt(to))
#define _2dC(str)		edip_packet(str, 9, _pt(from), _pt(to), C)

#define edip_lineColor(fg, bg)		_color("FG")
#define edip_linePattern(p)			_1("GM",p)
#define edip_pointSize(x_z, y_z)	_zoom("GZ")
#define edip_border(type, orient)	edip_packet("RE", 2, type, orient)
#define edip_borderColor(o, i, f)	edip_packet("FR", 3, o, i, f)

#define edip_drawLine(from, to)		_2d("GD")
#define edip_drawLine2(to)			_1d("GW", to)
#define edip_drawBox(from, to)		_2d("GR")
#define edip_drawPoint(at)			_1d("GP", at)
#define edip_drawBG(from, to)		_2d("RL")
#define edip_drawFG(from, to)		_2d("RS")
#define edip_drawFill(from, to, C)	_2dC("RF")
#define edip_drawBorder(from, to)	_2d("RR")

#define edip_patternColor(fg, bg)		_color("FM")
#define edip_paternArea(from, to, C)	_2dC("RM")
#define edip_paternBox(from, to, C)		_2dC("RO")

#define edip_bmpColor(fg bg)	_color("FU")
#define edip_bmpZoom(x_z, y_z)	_zoom("UZ")
#define edip_bmpOrient(o)		_1("UW", o)
#define edip_bmpMirror(hoz)		_1("UX", hoz)
#define edip_bmpTrans(type)		_1("UT", type)

extern void edip_bmpLoad(POINT at, BYTE *data) // "UI _pt(at) *data... 
#define edip_imgLoad(at, img)	edip_packet("UI", 5, _pt(at), img)
#define edip_imgCopy(from, to)	_2d("UH")

#define edip_gifColor(fg, bg)	_color("FW")
#define edip_gifZoom(x_z, y_z)	_zoom("WZ")
#define edip_gifOrient(o)		_1("WW", o)
#define edip_gifMirror(hoz)		_1("WX", hoz)
#define edip_gifTrans(type)		_1("WT", type)

#define _id(str, l)		edip_packet(str, l+1, id

#define edip_gifLoad(at, gif, img)	edip_packet("WI", 6, _pt(at), gif, img)
#define edip_gifDef(id, at, img, type, time) 	_id(7, "WD"), _pt(at), img, type, time)
#define edip_gifTime(id, time) 		_id("WC",1), time)
#define edip_gifType(id, type)	 	_id("WY",1), type)
#define edip_gifNext(id)			_id("WN",0))
#define edip_gifPrev(id)			_id("WP",0))
#define edip_gifShow(id, img)		_id("WF",1), img)
#define edip_gifRunTo(id, img)		_id("WM",1), img)
#define edip_gifSTop(id)			_id("WL",0))

#define edip_barColor(fg, bg, fc)	edip_packet("FB", 3, fg, bg, fc)
#define edip_barPattern(p)			_1("BM", p)
#define edip_barBorder(b)			_1("BE", b)
#define edip_barWidth(lw)			_1("BB", lw)
extern void edip_barDef(BYTE pos, BYTE id, POINT from, POINT to, BYTE min, BYTE max, BYTE type);	// "B$pos" bar _pt(from) _pt(to) min max type
#define edip_barUpdate(id, val)		_id("BA",1), val)
#define edip_barDraw(id)			_id("BN",0))
#define edip_barRead(id)			_id("BS",0))
#define edip_barDel(id, clear)		_id("BD",1), clear)

#define edip_barUVColor(fg, bg)		_color("FX")
#define edip_barUVFont(font)		_1("BF", font)
#define edip_barUVZoom(x_z, y_z)	_zoom("BZ")
#define edip_barUVZoom2(x_z, y_z)	_zoom("BY")
#define edip_barUVOrient(o)			_1("BW", o)
extern void edip_barUVScale(BYET id, POINT at, BYTE *str);	// "BX" id _pt(at) str...

#define edip_ainCalibrate(id, val)	_id("V@",1), val)
#define edip_ain(enable)			_1("VA",enable)
#define edip_ainRead(id)			_id("VD",0))
#define edip_ainMacroLim(id, min, max, hist)	_id("VK",3), min, max, hist)
#define edip_ainMacroDef(a, b)		edip_packet("VM", 2, a, b)
#define edip_ainSetBar(id, bar)		_id("VB",1),bar)
#define edip_ainDrawBars(id)		_id("VR",0))

#define edip_ainUVColor(fg, bg)		_id("FV",2), fg, bg)
#define edip_ainUVFont(font)		_id("VF",1), font)
#define edip_ainUVZoom(x_z, y_z)	_id("VZ",2), x_z, y_z)
#define edip_ainUVZoom2(x_z, y_z)	_id("VY",2), x_z, y_z)
#define edip_ainUVOrient(o)			_id("VW",1), o)
extern void edip_ainUVScale(BYET id, BYTE *str);	// "VE" id str...
#define edip_ainUVRead(id)			_id("VS",0))
#define edip_ainUVPrint(id)			_id("VT",0))
#define edip_ainUVAt(id, at)		_id("VT",4), _pt(at))

#define _macro(str)		edip_packet(str, 1, id)
#define edip_mNormal(id)	_macro("MN")
#define edip_mTouch(id)		_macro("MT")
#define edip_mPort(id)		_macro("MP")
#define edip_mBit(id)		_macro("MB")
#define edip_mMatrix(id)	_macro("MX")
#define edip_mProc(id)		_macro("MC")
#define edip_mAIN(id)		_macro("MV")
#define edip_m(enable, type, from, to)	edip_packet(enalbe?"MU":"ML", 1, type, from, to)
#define edip_mPage(p)		_1("MK",p)
#define edip_mPageSave()	_0("MW")
#define edip_mPageLoad()	_0("MR")

#define edip_mDelay(id, delay)	_id("MG",1), delay)
#define edip_mOnce(id, to, pause)	_id("ME",2), to, pause)
#define edip_mCycle(id, to, pause)	_id("MA",2), to, pause)
#define edip_mPing(id, to, pause)	_id("MJ",2), to, pause)

#define edip_mprocDef(id, type, from, to, pause)	_id("MD", 4), type, from, to, pause)
#define edip_mprocInterval(id, pause)	_id("MZ", 1), pause)
#define edip_mproc(enalbe)	_1("MS", enable)

#define edip_touchBorder