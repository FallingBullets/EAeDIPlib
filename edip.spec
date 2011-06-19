
bmpColor(fg bg)		packetColor("FU")
bmpZoom(zoom)		packet1D("UZ" zoom)
bmpOrient(o)		ESC "UW" o
bmpMirror(h)		ESC "UX" h
bmpTrans(type)		ESC "UT" type

bmpLoad(p data)	packet1D("UL" p) data
imgLoad(p)		packet1D("UI" p)
bmpSave(from to)	packet2D("UH")

gifColor(fg bg)		packetColor("FW")
gifZoom(zoom)		packet1D("WZ" zoom)
gifOrient(o)		ESC "WW" o
gifMirror(h)		ESC "WX" h
gifTrans(type)		ESC "WT" type
gifLoad(p gif img)	packet1D("WI" p) gif img
gifDef(id p img type time) 	ESC "WD id p.x p.y img type time
gifDefTime(id time) 		ESC "WC" id time
gifDefType(id type) 		ESC "WY" id type
gifNext(id)			ESC "WN" id
gifPrev(id)			ESC "WP" id
gifShow(id img)		ESC "WF" id img
gifRunTo(id img)	ESC "WM" id img
gifSTop(id)			ESC "WL" id

#termConf(e fg bg F C L W H)	ESC e?"TE":"TA" "\0" ESC "FT" fg bg "\0" ESC "TW" F C L W H)
#cursorConf(e C L) ESC "TC" e "\0" ESC "TP" C L
#displayConf(fg bg orient)
#fontConf(font fg bg zoom zp dot orient)
#confLine(fg bg patern)	ESC "FG" fg bg "\0" ESC "GM" p
