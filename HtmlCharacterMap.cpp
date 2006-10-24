#include <vector>
#include <string>

#include "UnicodeCharacter.h"
#include "HtmlCharacterMap.h"


namespace DoxEngine
{

  HtmlCharacterMaps::HtmlCharacterMaps():HtmlCharacterMapsBase()
  {
	HtmlCharacterMaps &maps = *this;


	// Character entity references for 8859-1 HTML4.01 section 24.2
	maps["nbsp"] = (unsigned long)160;
	maps["iexcl"] = (unsigned long)161;
	maps["cent"] = (unsigned long)162;
	maps["pound"] = (unsigned long)163;
  maps["curren"] = (unsigned long)164;
  maps["yen"] = (unsigned long)165;
  maps["brvbar"] = (unsigned long)166;
    maps["sect"] = (unsigned long)167;
    maps["uml"] = (unsigned long)168;
    maps["copy"] = (unsigned long)169;
    maps["ordf"] = (unsigned long)170;
    maps["laquo"] = (unsigned long)171;
    maps["not"] = (unsigned long)172;
    maps["shy"] = (unsigned long)173;
    maps["reg"] = (unsigned long)174;
    maps["macr"] = (unsigned long)175;
    maps["deg"] = (unsigned long)176;
    maps["plusmn"] = (unsigned long)177;
    maps["sup2"] = (unsigned long)178;
    maps["sup3"] = (unsigned long)179;
    maps["acute"] = (unsigned long)180;
    maps["micro"] = (unsigned long)181;
    maps["para"] = (unsigned long)182;
    maps["middot"] = (unsigned long)183;
    maps["cedil"] = (unsigned long)184;
    maps["sup1"] = (unsigned long)185;
    maps["ordm"] = (unsigned long)186;
    maps["raquo"] = (unsigned long)187;
    maps["frac14"] =(unsigned long)188;
    maps["frac12"] =(unsigned long)189;
    maps["frac34"] =(unsigned long)190;
    maps["iquest"] =(unsigned long)191;
    maps["Agrave"] =(unsigned long)192;
    maps["Aacute"] =(unsigned long)193;
    maps["Acirc"] =(unsigned long)194;
    maps["Atilde"] =(unsigned long)195;
    maps["Auml"] =(unsigned long)196;
    maps["Aring"] =(unsigned long)197;
    maps["AElig"] =(unsigned long)198;
    maps["Ccedil"] =(unsigned long)199;
    maps["Egrave"] =(unsigned long)200;
    maps["Eacute"] =(unsigned long)201;
    maps["Ecirc"] =(unsigned long)202;
    maps["Euml"] =(unsigned long)203;
    maps["Igrave"] =(unsigned long)204;
    maps["Iacute"] =(unsigned long)205;
    maps["Icirc"] =(unsigned long)206;
    maps["Iuml"] =(unsigned long)207;
    maps["ETH"] =(unsigned long)208;
    maps["Ntilde"] =(unsigned long)209;
    maps["Ograve"] =(unsigned long)210;
    maps["Oacute"] =(unsigned long)211;
    maps["Ocirc"] =(unsigned long)212;
    maps["Otilde"] =(unsigned long)213;
    maps["Ouml"] =(unsigned long)214;
    maps["times"] =(unsigned long)215;
    maps["Oslash"] =(unsigned long)216;
    maps["Ugrave"] =(unsigned long)217;
    maps["Uacute"] =(unsigned long)218;
    maps["Ucirc"] =(unsigned long)219;
    maps["Uuml"] =(unsigned long)220;
    maps["Yacute"] =(unsigned long)221;
    maps["THORN"] =(unsigned long)222;
    maps["szlig"] =(unsigned long)223;


    maps["agrave"] = (unsigned long)224;
    maps["aacute"] = (unsigned long)225;
    maps["acirc"] = (unsigned long)226;
    maps["atilde"] = (unsigned long)227;
    maps["auml"] = (unsigned long)228;
    maps["aring"] = (unsigned long)229;
    maps["aelig"] = (unsigned long)230;
    maps["ccedil"] = (unsigned long)231;
    maps["egrave"] = (unsigned long)232;
    maps["eacute"] = (unsigned long)233;
    maps["ecirc"] = (unsigned long)234;
    maps["euml"] = (unsigned long)235;
    maps["igrave"] = (unsigned long)236;
    maps["iacute"] = (unsigned long)237;
    maps["icirc"] = (unsigned long)238;
    maps["iuml"] = (unsigned long)239;
    maps["eth"] = (unsigned long)240;
    maps["ntilde"] = (unsigned long)241;
    maps["ograve"] = (unsigned long)242;
    maps["oacute"] = (unsigned long)243;
    maps["ocirc"] = (unsigned long)244;
    maps["otilde"] = (unsigned long)245;
    maps["ouml"] = (unsigned long)246;
    maps["divide"] = (unsigned long)247;
    maps["oslash"] = (unsigned long)248;
    maps["ugrave"] = (unsigned long)249;
    maps["uacute"] = (unsigned long)250;
    maps["ucirc"] = (unsigned long)251;
    maps["uuml"] = (unsigned long)252;
    maps["yacute"] = (unsigned long)253;
    maps["thorn"] = (unsigned long)254;
    maps["yuml"] = (unsigned long)255;



    // Character reference entities for HTML control characters
    // HTML4.01 section 24.4.1

    maps["quot"] = (unsigned long)34;
    maps["amp"] = (unsigned long)38;
    maps["lt"] = (unsigned long)60;
    maps["gt"] = (unsigned long)62;
  }

}





