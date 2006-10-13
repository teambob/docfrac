#include <vector>
#include <string>

#include "UnicodeCharacter.h"
#include "HtmlCharacterMap.h"


namespace DoxEngine
{


  HtmlCharacterMap::HtmlCharacterMap(const std::string &newId,
	const UnicodeCharacter &newCharacter):character(newCharacter),id(newId)
  {
  }

  HtmlCharacterMap::~HtmlCharacterMap()
  {
  }

  void HtmlCharacterMap::setMap(const std::string &newId,
	const UnicodeCharacter& newCharacter)
  {
	id = newId;
	character = newCharacter;
  }

  bool HtmlCharacterMap::operator==(const std::string &rhs) const
  {
	return id==rhs;
  }

  bool HtmlCharacterMap::operator!=(const std::string &rhs) const
  {
	return id!=rhs;
  }

  UnicodeCharacter HtmlCharacterMap::getCharacter(void)
  {
    return character;
  }


  HtmlCharacterMapsFactory& HtmlCharacterMapsFactory::instance(void)
  {
	static HtmlCharacterMapsFactory singleton;

	return singleton;
  }

  HtmlCharacterMaps HtmlCharacterMapsFactory::getMaps(void)
  {
	HtmlCharacterMaps maps;


	// Character entity references for 8859-1 HTML4.01 section 24.2
	HtmlCharacterMap map("nbsp", (unsigned long)160);
	maps.push_back(map);

	map.setMap("iexcl", (unsigned long)161);
	maps.push_back(map);

	map.setMap("cent", (unsigned long)162);
	maps.push_back(map);

	map.setMap("pound", (unsigned long)163);
	maps.push_back(map);

    map.setMap("curren", (unsigned long)164);
    maps.push_back(map);

    map.setMap("yen", (unsigned long)165);
    maps.push_back(map);

    map.setMap("brvbar", (unsigned long)166);
    maps.push_back(map);

    map.setMap("sect", (unsigned long)167);
    maps.push_back(map);

    map.setMap("uml", (unsigned long)168);
    maps.push_back(map);

    map.setMap("copy", (unsigned long)169);
    maps.push_back(map);

    map.setMap("ordf", (unsigned long)170);
    maps.push_back(map);

    map.setMap("laquo", (unsigned long)171);
    maps.push_back(map);

    map.setMap("not", (unsigned long)172);
    maps.push_back(map);

    map.setMap("shy", (unsigned long)173);
    maps.push_back(map);

    map.setMap("reg", (unsigned long)174);
    maps.push_back(map);

    map.setMap("macr", (unsigned long)175);
    maps.push_back(map);

    map.setMap("deg", (unsigned long)176);
    maps.push_back(map);

    map.setMap("plusmn", (unsigned long)177);
    maps.push_back(map);

    map.setMap("sup2", (unsigned long)178);
    maps.push_back(map);

    map.setMap("sup3", (unsigned long)179);
    maps.push_back(map);

    map.setMap("acute", (unsigned long)180);
    maps.push_back(map);

    map.setMap("micro", (unsigned long)181);
    maps.push_back(map);

    map.setMap("para", (unsigned long)182);
    maps.push_back(map);

    map.setMap("middot", (unsigned long)183);
    maps.push_back(map);

    map.setMap("cedil", (unsigned long)184);
    maps.push_back(map);

    map.setMap("sup1", (unsigned long)185);
    maps.push_back(map);

    map.setMap("ordm", (unsigned long)186);
    maps.push_back(map);

    map.setMap("raquo", (unsigned long)187);
    maps.push_back(map);

    map.setMap("frac14", (unsigned long)188);
    maps.push_back(map);

    map.setMap("frac12", (unsigned long)189);
    maps.push_back(map);

    map.setMap("frac34", (unsigned long)190);
    maps.push_back(map);

    map.setMap("iquest", (unsigned long)191);
    maps.push_back(map);

    map.setMap("Agrave", (unsigned long)192);
    maps.push_back(map);

    map.setMap("Aacute", (unsigned long)193);
    maps.push_back(map);

    map.setMap("Acirc", (unsigned long)194);
    maps.push_back(map);

    map.setMap("Atilde", (unsigned long)195);
    maps.push_back(map);

    map.setMap("Auml", (unsigned long)196);
    maps.push_back(map);

    map.setMap("Aring", (unsigned long)197);
    maps.push_back(map);

    map.setMap("AElig", (unsigned long)198);
    maps.push_back(map);

    map.setMap("Ccedil", (unsigned long)199);
    maps.push_back(map);

    map.setMap("Egrave", (unsigned long)200);
    maps.push_back(map);

    map.setMap("Eacute", (unsigned long)201);
    maps.push_back(map);

    map.setMap("Ecirc", (unsigned long)202);
    maps.push_back(map);

    map.setMap("Euml", (unsigned long)203);
    maps.push_back(map);

    map.setMap("Igrave", (unsigned long)204);
    maps.push_back(map);

    map.setMap("Iacute", (unsigned long)205);
    maps.push_back(map);

    map.setMap("Icirc", (unsigned long)206);
    maps.push_back(map);

    map.setMap("Iuml", (unsigned long)207);
    maps.push_back(map);

    map.setMap("ETH", (unsigned long)208);
    maps.push_back(map);

    map.setMap("Ntilde", (unsigned long)209);
    maps.push_back(map);

    map.setMap("Ograve", (unsigned long)210);
    maps.push_back(map);

    map.setMap("Oacute", (unsigned long)211);
    maps.push_back(map);

    map.setMap("Ocirc", (unsigned long)212);
    maps.push_back(map);

    map.setMap("Otilde", (unsigned long)213);
    maps.push_back(map);

    map.setMap("Ouml", (unsigned long)214);
    maps.push_back(map);

    map.setMap("times", (unsigned long)215);
    maps.push_back(map);

    map.setMap("Oslash", (unsigned long)216);
    maps.push_back(map);

    map.setMap("Ugrave", (unsigned long)217);
    maps.push_back(map);

    map.setMap("Uacute", (unsigned long)218);
    maps.push_back(map);

    map.setMap("Ucirc", (unsigned long)219);
    maps.push_back(map);

    map.setMap("Uuml", (unsigned long)220);
    maps.push_back(map);

    map.setMap("Yacute", (unsigned long)221);
    maps.push_back(map);

    map.setMap("THORN", (unsigned long)222);
    maps.push_back(map);

    map.setMap("szlig", (unsigned long)223);
    maps.push_back(map);











    map.setMap("agrave", (unsigned long)224);
    maps.push_back(map);

    map.setMap("aacute", (unsigned long)225);
    maps.push_back(map);

    map.setMap("acirc", (unsigned long)226);
    maps.push_back(map);

    map.setMap("atilde", (unsigned long)227);
    maps.push_back(map);

    map.setMap("auml", (unsigned long)228);
    maps.push_back(map);

    map.setMap("aring", (unsigned long)229);
    maps.push_back(map);

    map.setMap("aelig", (unsigned long)230);
    maps.push_back(map);

    map.setMap("ccedil", (unsigned long)231);
    maps.push_back(map);

    map.setMap("egrave", (unsigned long)232);
    maps.push_back(map);

    map.setMap("eacute", (unsigned long)233);
    maps.push_back(map);

    map.setMap("ecirc", (unsigned long)234);
    maps.push_back(map);

    map.setMap("euml", (unsigned long)235);
    maps.push_back(map);

    map.setMap("igrave", (unsigned long)236);
    maps.push_back(map);

    map.setMap("iacute", (unsigned long)237);
    maps.push_back(map);

    map.setMap("icirc", (unsigned long)238);
    maps.push_back(map);

    map.setMap("iuml", (unsigned long)239);
    maps.push_back(map);

    map.setMap("eth", (unsigned long)240);
    maps.push_back(map);

    map.setMap("ntilde", (unsigned long)241);
    maps.push_back(map);

    map.setMap("ograve", (unsigned long)242);
    maps.push_back(map);

    map.setMap("oacute", (unsigned long)243);
    maps.push_back(map);

    map.setMap("ocirc", (unsigned long)244);
    maps.push_back(map);

    map.setMap("otilde", (unsigned long)245);
    maps.push_back(map);

    map.setMap("ouml", (unsigned long)246);
    maps.push_back(map);

    map.setMap("divide", (unsigned long)247);
    maps.push_back(map);

    map.setMap("oslash", (unsigned long)248);
    maps.push_back(map);

    map.setMap("ugrave", (unsigned long)249);
    maps.push_back(map);

    map.setMap("uacute", (unsigned long)250);
    maps.push_back(map);

    map.setMap("ucirc", (unsigned long)251);
    maps.push_back(map);

    map.setMap("uuml", (unsigned long)252);
    maps.push_back(map);

    map.setMap("yacute", (unsigned long)253);
    maps.push_back(map);

    map.setMap("thorn", (unsigned long)254);
    maps.push_back(map);

    map.setMap("yuml", (unsigned long)255);
    maps.push_back(map);


    // Character reference entities for HTML control characters
    // HTML4.01 section 24.4.1

    map.setMap("quot", (unsigned long)34);
    maps.push_back(map);

    map.setMap("amp", (unsigned long)38);
    maps.push_back(map);

    map.setMap("lt", (unsigned long)60);
    maps.push_back(map);

    map.setMap("gt", (unsigned long)62);
    maps.push_back(map);





	return maps;

  }

}





