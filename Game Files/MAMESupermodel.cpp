/*This file is part of FFB Arcade Plugin.
FFB Arcade Plugin is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
FFB Arcade Plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with FFB Arcade Plugin.If not, see < https://www.gnu.org/licenses/>.
*/

#include "MAMESupermodel.h"
#include <string>
#include <tchar.h>
#include <atlstr.h>
#include "SDL.h"
#include "../Common Files/SignatureScanning.h"

static char GameName[256];

static EffectConstants* myconstants;
static Helpers* myhelpers;
static EffectTriggers* mytriggers;

//MAME Games
std::string acedrive("acedrive");
std::string acedrvrw("acedrvrw");
std::string vformula("vformula");
std::string vr("vr");
std::string sfrush("sfrush");
std::string sfrushrk("sfrushrk");
std::string sfrushrkwo("sfrushrkwo");
std::string sfrusha("sfrusha");
std::string crusnwld("crusnwld");
std::string crusnwld24("crusnwld24");
std::string crusnwld23("crusnwld23");
std::string crusnwld20("crusnwld20");
std::string crusnwld19("crusnwld19");
std::string crusnwld17("crusnwld17");
std::string crusnwld13("crusnwld13");
std::string daytona("daytona");
std::string daytonas("daytonas");
std::string daytonase("daytonase");
std::string dirtdash("dirtdash");
std::string dirtdasha("dirtdasha");
std::string dirtdashj("dirtdashj");
std::string offroadc("offroadc");
std::string offroadc4("offroadc4");
std::string offroadc3("offroadc3");
std::string offroadc1("offroadc1");
std::string crusnusa("crusnusa");
std::string crusnusa40("crusnusa40");
std::string crusnusa21("crusnusa21");
std::string calspeed("calspeed");
std::string calspeeda("calspeeda");
std::string calspeedb("calspeedb");
std::string indy500("indy500");
std::string indy500d("indy500d");
std::string indy500to("indy500to");
std::string outrunra("outrunra");
std::string outrun("outrun");
std::string outruneh("outruneh");
std::string toutrun("toutrun");
std::string toutrund("toutrund");
std::string toutrunj("toutrunj");
std::string toutrunjd("toutrunjd");
std::string pdrift("pdrift");
std::string pdrifta("pdrifta");
std::string pdrifte("pdrifte");
std::string pdriftj("pdriftj");
std::string pdriftl("pdriftl");
std::string orunners("orunners");
std::string orunnersu("orunnersu");
std::string orunnersj("orunnersj");
std::string sf2049("sf2049");
std::string sf2049se("sf2049se");
std::string sf2049te("sf2049te");
std::string harddriv("harddriv");
std::string harddriv1("harddriv1");
std::string harddrivb6("harddrivb6");
std::string harddrivb("harddrivb");
std::string harddrivg4("harddrivg4");
std::string harddrivg("harddrivg");
std::string harddrivj6("harddrivj6");
std::string harddrivj("harddrivj");
std::string harddriv2("harddriv2");
std::string harddriv3("harddriv3");
std::string harddrivcb("harddrivcb");
std::string harddrivcg("harddrivcg");
std::string harddrivc1("harddrivc1");
std::string harddrivc("harddrivc");
std::string hdrivairp("hdrivairp");
std::string hdrivair("hdrivair");
std::string racedrivb1("racedrivb1");
std::string racedrivb4("racedrivb4");
std::string racedrivb("racedrivb");
std::string racedrivg1("racedrivg1");
std::string racedrivg4("racedrivg4");
std::string racedrivg("racedrivg");
std::string racedriv1("racedriv1");
std::string racedriv2("racedriv2");
std::string racedriv3("racedriv3");
std::string racedriv4("racedriv4");
std::string racedriv("racedriv");
std::string racedrivcb4("racedrivcb4");
std::string racedrivcb("racedrivcb");
std::string racedrivcg4("racedrivcg4");
std::string racedrivcg("racedrivcg");
std::string racedrivc2("racedrivc2");
std::string racedrivc4("racedrivc4");
std::string racedrivc("racedrivc");
std::string racedrivpan("racedrivpan");
std::string raverace("raverace");
std::string raveracw("raveracw");
std::string raveracj("raveracj");
std::string raveracja("raveracja");
std::string sgt24h("sgt24h");
std::string srallyc("srallyc");
std::string srallycb("srallycb");
std::string srallycdxa("srallycdxa");
std::string srallycdx("srallycdx");
std::string spacegun("spacegun");
std::string spacegunu("spacegunu");
std::string spacegunj("spacegunj");
std::string superchs("superchs");
std::string superchsp("superchsp");
std::string superchsj("superchsj");
std::string superchsu("superchsu");
std::string stcc("stcc");
std::string stcca("stcca");
std::string stccb("stccb");
std::string cischeat("cischeat");
std::string f1gpstar("f1gpstar");
std::string f1gpstaro("f1gpstaro");
std::string f1gpstr2("f1gpstr2");
std::string cbombers("cbombers");
std::string cbombersj("cbombersj");
std::string cbombersp("cbombersp");
std::string hyprdriv("hyprdriv");
std::string vaportrx("vaportrx");
std::string vaportrp("vaportrp");
std::string victlapw("victlapw");
std::string victlap("victlap");
std::string dblaxle("dblaxle");
std::string dblaxleu("dblaxleu");
std::string windheat("windheat");
std::string windheatj("windheatj");
std::string windheatu("windheatu");
std::string windheata("windheata");
std::string gticlub("gticlub");
std::string gticlubj("gticlubj");
std::string gticlubu("gticlubu");
std::string gticluba("gticluba");
std::string midnrun("midnrun");
std::string midnruna("midnruna");
std::string midnruna2("midnruna2");
std::string midnrunj("midnrunj");
std::string roadedge("roadedge");
std::string xrally("xrally");
std::string cartfury("cartfury");
std::string thrilld("thrilld");
std::string thrillda("thrillda");
std::string thrillde("thrillde");
std::string thrilldj("thrilldj");
std::string racingj("racingj");
std::string racingja("racingja");
std::string racingje("racingje");
std::string racingju("racingju");
std::string racingjj("racingjj");
std::string racingj2("racingj2");
std::string racingj2a("racingj2a");
std::string racingj2e("racingj2e");
std::string racingj2u("racingj2u");
std::string racingj2j("racingj2j");
std::string overrev("overrev");
std::string overrevb("overrevb");
std::string overrevba("overrevba");

//Our string to load game from
std::string VirtuaRacingActive("VirtuaRacingActive");
std::string HardDrivinActive("HardDrivinActive");
std::string NamcoFFBActive("NamcoFFBActive");
std::string NamcoFFBNew("NamcoFFBNew");
std::string RacingFullValueActive1("RacingFullValueActive1");
std::string RacingFullValueActive2("RacingFullValueActive2");
std::string RacingActive1("RacingActive1");
std::string RacingActive2("RacingActive2");
std::string OutrunActive("OutrunActive");
std::string PDriftActive("PDriftActive");
std::string SuperChaseActive("SuperChaseActive");
std::string srallynew("srallynew");
std::string m2new("m2new");
std::string RaveRacerNew("RaveRacerNew");
std::string Konami("Konami");
std::string hng64("hng64");

//Names of FFB Outputs
std::string digit0("digit0");
std::string wheel("wheel");
std::string wheel0("wheel0");
std::string pcboutput0("pcboutput0");
std::string mcuoutput1("mcuoutput1");
std::string output0("output0");
std::string wheel_motor("wheel_motor");
std::string led2("led2");
std::string cpuled6("cpuled6");
std::string Vibration_motor("Vibration_motor");
std::string vibration_motor("vibration_motor");
std::string Wheel_vibration("Wheel_vibration");
std::string Wheel_Vibration("Wheel_Vibration");
std::string upright_wheel_motor("upright_wheel_motor");
std::string MA_Steering_Wheel_motor("MA_Steering_Wheel_motor");
std::string MB_Steering_Wheel_motor("MB_Steering_Wheel_motor");
std::string mcuout1("mcuout1");
std::string mcuout3("mcuout3");
std::string Bank_Motor_Speed("Bank_Motor_Speed");
std::string Bank_Motor_Direction("Bank_Motor_Direction");
std::string bank_motor_position("bank_motor_position");
std::string genout2("genout2");

HINSTANCE ProcDLL = NULL;
extern int joystick_index1;
extern int joystick_index2;
extern int joystick_index3;
extern SDL_Joystick* GameController2;
extern SDL_Haptic* ControllerHaptic2;
extern SDL_Haptic* haptic2;
extern SDL_Joystick* GameController3;
extern SDL_Haptic* ControllerHaptic3;
extern SDL_Haptic* haptic3;

//Config Settings
extern wchar_t* settingsFilename;
extern int DeviceGUID;
extern int enableLogging;
extern int configFeedbackLength;
extern int configGameId;
extern int AlternativeFFB;
extern int configMinForce;
extern int configMaxForce;
extern int PowerMode;
extern int EnableRumble;
extern int ReverseRumble;
extern int configFeedbackLength;
extern int configAlternativeMinForceLeft;
extern int configAlternativeMaxForceLeft;
extern int configAlternativeMinForceRight;
extern int configAlternativeMaxForceRight;
extern int configMinForceDevice2;
extern int configMaxForceDevice2;
extern int EnableRumbleDevice2;
extern int ReverseRumbleDevice2;
extern int configAlternativeMinForceLeftDevice2;
extern int configAlternativeMaxForceLeftDevice2;
extern int configAlternativeMinForceRightDevice2;
extern int configAlternativeMaxForceRightDevice2;
extern int configMinForceDevice3;
extern int configMaxForceDevice3;
extern int EnableRumbleDevice3;
extern int ReverseRumbleDevice3;
extern int configAlternativeMinForceLeftDevice3;
extern int configAlternativeMaxForceLeftDevice3;
extern int configAlternativeMinForceRightDevice3;
extern int configAlternativeMaxForceRightDevice3;
extern int SinePeriod;
extern int SineFadePeriod;
extern int SineStrength;
extern int RumbleStrengthLeftMotor;
extern int RumbleStrengthRightMotor;
extern int EnableForceSpringEffect;
extern int ForceSpringStrength;
extern int EnableDamper;
extern int DamperStrength;
extern int DoubleConstant;
extern int DoubleSine;

static int UseConstantInf = GetPrivateProfileInt(TEXT("Settings"), TEXT("UseConstantInf"), 1, settingsFilename);
static int ReverseDirection = GetPrivateProfileInt(TEXT("Settings"), TEXT("ReverseDirection"), 0, settingsFilename);

static int configMinForceOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceOverRev"), 0, settingsFilename);
static int configMaxForceOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceOverRev"), 100, settingsFilename);
static int configAlternativeMinForceLeftOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftOverRev"), 0, settingsFilename);
static int configAlternativeMaxForceLeftOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftOverRev"), 100, settingsFilename);
static int configAlternativeMinForceRightOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightOverRev"), 0, settingsFilename);
static int configAlternativeMaxForceRightOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightOverRev"), 100, settingsFilename);
static int configFeedbackLengthOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthOverRev"), 120, settingsFilename);
static int PowerModeOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeOverRev"), 0, settingsFilename);
static int EnableForceSpringEffectOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectOverRev"), 0, settingsFilename);
static int ForceSpringStrengthOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthOverRev"), 0, settingsFilename);
static int EnableDamperOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperOverRev"), 0, settingsFilename);
static int DamperStrengthOverRev = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthOverRev"), 100, settingsFilename);

static int configMinForceCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceCartFury"), 0, settingsFilename);
static int configMaxForceCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceCartFury"), 100, settingsFilename);
static int configAlternativeMinForceLeftCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftCartFury"), 0, settingsFilename);
static int configAlternativeMaxForceLeftCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftCartFury"), 100, settingsFilename);
static int configAlternativeMinForceRightCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightCartFury"), 0, settingsFilename);
static int configAlternativeMaxForceRightCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightCartFury"), 100, settingsFilename);
static int configFeedbackLengthCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthCartFury"), 120, settingsFilename);
static int PowerModeCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeCartFury"), 0, settingsFilename);
static int EnableForceSpringEffectCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectCartFury"), 0, settingsFilename);
static int ForceSpringStrengthCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthCartFury"), 0, settingsFilename);
static int EnableDamperCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperCartFury"), 0, settingsFilename);
static int DamperStrengthCartFury = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthCartFury"), 100, settingsFilename);

static int configMinForceThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceThrillD"), 0, settingsFilename);
static int configMaxForceThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceThrillD"), 100, settingsFilename);
static int configAlternativeMinForceLeftThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftThrillD"), 0, settingsFilename);
static int configAlternativeMaxForceLeftThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftThrillD"), 100, settingsFilename);
static int configAlternativeMinForceRightThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightThrillD"), 0, settingsFilename);
static int configAlternativeMaxForceRightThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightThrillD"), 100, settingsFilename);
static int configFeedbackLengthThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthThrillD"), 120, settingsFilename);
static int PowerModeThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeThrillD"), 0, settingsFilename);
static int EnableForceSpringEffectThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectThrillD"), 0, settingsFilename);
static int ForceSpringStrengthThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthThrillD"), 0, settingsFilename);
static int EnableDamperThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperThrillD"), 0, settingsFilename);
static int DamperStrengthThrillD = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthThrillD"), 100, settingsFilename);

static int configMinForceWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceWindheat"), 0, settingsFilename);
static int configMaxForceWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceWindheat"), 100, settingsFilename);
static int configAlternativeMinForceLeftWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftWindheat"), 0, settingsFilename);
static int configAlternativeMaxForceLeftWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftWindheat"), 100, settingsFilename);
static int configAlternativeMinForceRightWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightWindheat"), 0, settingsFilename);
static int configAlternativeMaxForceRightWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightWindheat"), 100, settingsFilename);
static int configFeedbackLengthWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthWindheat"), 120, settingsFilename);
static int PowerModeWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeWindheat"), 0, settingsFilename);
static int EnableForceSpringEffectWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectWindheat"), 0, settingsFilename);
static int ForceSpringStrengthWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthWindheat"), 0, settingsFilename);
static int EnableDamperWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperWindheat"), 0, settingsFilename);
static int DamperStrengthWindheat = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthWindheat"), 100, settingsFilename);

static int configMinForceMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceMidnRun"), 0, settingsFilename);
static int configMaxForceMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceMidnRun"), 100, settingsFilename);
static int configAlternativeMinForceLeftMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftMidnRun"), 0, settingsFilename);
static int configAlternativeMaxForceLeftMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftMidnRun"), 100, settingsFilename);
static int configAlternativeMinForceRightMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightMidnRun"), 0, settingsFilename);
static int configAlternativeMaxForceRightMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightMidnRun"), 100, settingsFilename);
static int configFeedbackLengthMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthMidnRun"), 120, settingsFilename);
static int PowerModeMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeMidnRun"), 0, settingsFilename);
static int EnableForceSpringEffectMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectMidnRun"), 0, settingsFilename);
static int ForceSpringStrengthMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthMidnRun"), 0, settingsFilename);
static int EnableDamperMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperMidnRun"), 0, settingsFilename);
static int DamperStrengthMidnRun = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthMidnRun"), 100, settingsFilename);

static int configMinForceRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceRacingJ"), 0, settingsFilename);
static int configMaxForceRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceRacingJ"), 100, settingsFilename);
static int configAlternativeMinForceLeftRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftRacingJ"), 0, settingsFilename);
static int configAlternativeMaxForceLeftRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftRacingJ"), 100, settingsFilename);
static int configAlternativeMinForceRightRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightRacingJ"), 0, settingsFilename);
static int configAlternativeMaxForceRightRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightRacingJ"), 100, settingsFilename);
static int configFeedbackLengthRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthRacingJ"), 120, settingsFilename);
static int PowerModeRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeRacingJ"), 0, settingsFilename);
static int EnableForceSpringEffectRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectRacingJ"), 0, settingsFilename);
static int ForceSpringStrengthRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthRacingJ"), 0, settingsFilename);
static int EnableDamperRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperRacingJ"), 0, settingsFilename);
static int DamperStrengthRacingJ = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthRacingJ"), 100, settingsFilename);

static int configMinForceRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceRacingJ2"), 0, settingsFilename);
static int configMaxForceRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceRacingJ2"), 100, settingsFilename);
static int configAlternativeMinForceLeftRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftRacingJ2"), 0, settingsFilename);
static int configAlternativeMaxForceLeftRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftRacingJ2"), 100, settingsFilename);
static int configAlternativeMinForceRightRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightRacingJ2"), 0, settingsFilename);
static int configAlternativeMaxForceRightRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightRacingJ2"), 100, settingsFilename);
static int configFeedbackLengthRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthRacingJ2"), 120, settingsFilename);
static int PowerModeRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeRacingJ2"), 0, settingsFilename);
static int EnableForceSpringEffectRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectRacingJ2"), 0, settingsFilename);
static int ForceSpringStrengthRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthRacingJ2"), 0, settingsFilename);
static int EnableDamperRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperRacingJ2"), 0, settingsFilename);
static int DamperStrengthRacingJ2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthRacingJ2"), 100, settingsFilename);

static int configMinForceDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceDaytona"), 0, settingsFilename);
static int configMaxForceDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceDaytona"), 100, settingsFilename);
static int configAlternativeMinForceLeftDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftDaytona"), 0, settingsFilename);
static int configAlternativeMaxForceLeftDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftDaytona"), 100, settingsFilename);
static int configAlternativeMinForceRightDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightDaytona"), 0, settingsFilename);
static int configAlternativeMaxForceRightDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightDaytona"), 100, settingsFilename);
static int PowerModeDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeDaytona"), 0, settingsFilename);
static int configFeedbackLengthDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthDaytona"), 120, settingsFilename);
static int EnableForceSpringEffectDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectDaytona"), 0, settingsFilename);
static int ForceSpringStrengthDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthDaytona"), 0, settingsFilename);
static int EnableDamperDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperDaytona"), 0, settingsFilename);
static int DamperStrengthDaytonaMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthDaytona"), 100, settingsFilename);

static int configMinForceSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceSRally"), 0, settingsFilename);
static int configMaxForceSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceSRally"), 100, settingsFilename);
static int configAlternativeMinForceLeftSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftSRally"), 0, settingsFilename);
static int configAlternativeMaxForceLeftSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftSRally"), 100, settingsFilename);
static int configAlternativeMinForceRightSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightSRally"), 0, settingsFilename);
static int configAlternativeMaxForceRightSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightSRally"), 100, settingsFilename);
static int PowerModeSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeSRally"), 0, settingsFilename);
static int configFeedbackLengthSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthSRally"), 120, settingsFilename);
static int EnableForceSpringEffectSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectSRally"), 0, settingsFilename);
static int ForceSpringStrengthSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthSRally"), 0, settingsFilename);
static int EnableDamperSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperSRally"), 0, settingsFilename);
static int DamperStrengthSRallyMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthSRally"), 100, settingsFilename);

static int configMinForceSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceSTCC"), 0, settingsFilename);
static int configMaxForceSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceSTCC"), 100, settingsFilename);
static int configAlternativeMinForceLeftSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftSTCC"), 0, settingsFilename);
static int configAlternativeMaxForceLeftSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftSTCC"), 100, settingsFilename);
static int configAlternativeMinForceRightSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightSTCC"), 0, settingsFilename);
static int configAlternativeMaxForceRightSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightSTCC"), 100, settingsFilename);
static int PowerModeSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeSTCC"), 0, settingsFilename);
static int configFeedbackLengthSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthSTCC"), 120, settingsFilename);
static int EnableForceSpringEffectSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectSTCC"), 0, settingsFilename);
static int ForceSpringStrengthSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthSTCC"), 0, settingsFilename);
static int EnableDamperSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperSTCC"), 0, settingsFilename);
static int DamperStrengthSTCCMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthSTCC"), 100, settingsFilename);

static int configMinForceIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceIndy500"), 0, settingsFilename);
static int configMaxForceIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceIndy500"), 100, settingsFilename);
static int configAlternativeMinForceLeftIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftIndy500"), 0, settingsFilename);
static int configAlternativeMaxForceLeftIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftIndy500"), 100, settingsFilename);
static int configAlternativeMinForceRightIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightIndy500"), 0, settingsFilename);
static int configAlternativeMaxForceRightIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightIndy500"), 100, settingsFilename);
static int PowerModeIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeIndy500"), 0, settingsFilename);
static int configFeedbackLengthIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthIndy500"), 120, settingsFilename);
static int EnableForceSpringEffectIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectIndy500"), 0, settingsFilename);
static int ForceSpringStrengthIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthIndy500"), 0, settingsFilename);
static int EnableDamperIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperIndy500"), 0, settingsFilename);
static int DamperStrengthIndy500MAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthIndy500"), 100, settingsFilename);

static int configMinForceSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceSuperGT"), 0, settingsFilename);
static int configMaxForceSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceSuperGT"), 100, settingsFilename);
static int configAlternativeMinForceLeftSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftSuperGT"), 0, settingsFilename);
static int configAlternativeMaxForceLeftSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftSuperGT"), 100, settingsFilename);
static int configAlternativeMinForceRightSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightSuperGT"), 0, settingsFilename);
static int configAlternativeMaxForceRightSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightSuperGT"), 100, settingsFilename);
static int PowerModeSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeSuperGT"), 0, settingsFilename);
static int configFeedbackLengthSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthSuperGT"), 120, settingsFilename);
static int EnableForceSpringEffectSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectSuperGT"), 0, settingsFilename);
static int ForceSpringStrengthSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthSuperGT"), 0, settingsFilename);
static int EnableDamperSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperSuperGT"), 0, settingsFilename);
static int DamperStrengthSuperGTMAME = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthSuperGT"), 100, settingsFilename);

static int configMinForceGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceGTIClub"), 0, settingsFilename);
static int configMaxForceGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceGTIClub"), 100, settingsFilename);
static int configAlternativeMinForceLeftGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftGTIClub"), 0, settingsFilename);
static int configAlternativeMaxForceLeftGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftGTIClub"), 100, settingsFilename);
static int configAlternativeMinForceRightGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightGTIClub"), 0, settingsFilename);
static int configAlternativeMaxForceRightGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightGTIClub"), 100, settingsFilename);
static int configFeedbackLengthGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthGTIClub"), 120, settingsFilename);
static int PowerModeGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeGTIClub"), 0, settingsFilename);
static int EnableForceSpringEffectGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectGTIClub"), 0, settingsFilename);
static int ForceSpringStrengthGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthGTIClub"), 0, settingsFilename);
static int EnableDamperGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperGTIClub"), 0, settingsFilename);
static int DamperStrengthGTIClub = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthGTIClub"), 100, settingsFilename);

static int configMinForceRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceRoadEdge"), 0, settingsFilename);
static int configMaxForceRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceRoadEdge"), 100, settingsFilename);
static int configAlternativeMinForceLeftRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftRoadEdge"), 0, settingsFilename);
static int configAlternativeMaxForceLeftRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftRoadEdge"), 100, settingsFilename);
static int configAlternativeMinForceRightRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightRoadEdge"), 0, settingsFilename);
static int configAlternativeMaxForceRightRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightRoadEdge"), 100, settingsFilename);
static int PowerModeRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeRoadEdge"), 0, settingsFilename);
static int configFeedbackLengthRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthRoadEdge"), 120, settingsFilename);
static int EnableForceSpringEffectRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectRoadEdge"), 0, settingsFilename);
static int ForceSpringStrengthRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthRoadEdge"), 0, settingsFilename);
static int FFBDivideRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("FFBDivideRoadEdge"), 0, settingsFilename);
static int EnableDamperRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperRoadEdge"), 0, settingsFilename);
static int DamperStrengthRoadEdge = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthRoadEdge"), 100, settingsFilename);

static int configMinForceXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceXRally"), 0, settingsFilename);
static int configMaxForceXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceXRally"), 100, settingsFilename);
static int configAlternativeMinForceLeftXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftXRally"), 0, settingsFilename);
static int configAlternativeMaxForceLeftXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftXRally"), 100, settingsFilename);
static int configAlternativeMinForceRightXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightXRally"), 0, settingsFilename);
static int configAlternativeMaxForceRightXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightXRally"), 100, settingsFilename);
static int PowerModeXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeXRally"), 0, settingsFilename);
static int configFeedbackLengthXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthXRally"), 120, settingsFilename);
static int EnableForceSpringEffectXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectXRally"), 0, settingsFilename);
static int ForceSpringStrengthXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthXRally"), 0, settingsFilename);
static int FFBDivideXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("FFBDivideXRally"), 0, settingsFilename);
static int EnableDamperXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperXRally"), 0, settingsFilename);
static int DamperStrengthXRally = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthXRally"), 100, settingsFilename);

static int configMinForceVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceVirtuaRacing"), 0, settingsFilename);
static int configMaxForceVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceVirtuaRacing"), 100, settingsFilename);
static int configAlternativeMinForceLeftVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftVirtuaRacing"), 0, settingsFilename);
static int configAlternativeMaxForceLeftVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftVirtuaRacing"), 100, settingsFilename);
static int configAlternativeMinForceRightVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightVirtuaRacing"), 0, settingsFilename);
static int configAlternativeMaxForceRightVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightVirtuaRacing"), 100, settingsFilename);
static int configFeedbackLengthVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthVirtuaRacing"), 120, settingsFilename);
static int EnableForceSpringEffectVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectVirtuaRacing"), 0, settingsFilename);
static int ForceSpringStrengthVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthVirtuaRacing"), 0, settingsFilename);
static int EnableDamperVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperVirtuaRacing"), 0, settingsFilename);
static int DamperStrengthVirtuaRacing = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthVirtuaRacing"), 100, settingsFilename);

static int configMinForceSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceSFRush"), 0, settingsFilename);
static int configMaxForceSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceSFRush"), 100, settingsFilename);
static int configAlternativeMinForceLeftSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftSFRush"), 0, settingsFilename);
static int configAlternativeMaxForceLeftSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftSFRush"), 100, settingsFilename);
static int configAlternativeMinForceRightSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightSFRush"), 0, settingsFilename);
static int configAlternativeMaxForceRightSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightSFRush"), 100, settingsFilename);
static int configFeedbackLengthSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthSFRush"), 120, settingsFilename);
static int PowerModeSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeSFRush"), 0, settingsFilename);
static int EnableForceSpringEffectSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectSFRush"), 0, settingsFilename);
static int ForceSpringStrengthSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthSFRush"), 0, settingsFilename);
static int EnableDamperSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperSFRush"), 0, settingsFilename);
static int DamperStrengthSFRush = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthSFRush"), 100, settingsFilename);

static int configMinForceSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceSFRushRock"), 0, settingsFilename);
static int configMaxForceSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceSFRushRock"), 100, settingsFilename);
static int configAlternativeMinForceLeftSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftSFRushRock"), 0, settingsFilename);
static int configAlternativeMaxForceLeftSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftSFRushRock"), 100, settingsFilename);
static int configAlternativeMinForceRightSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightSFRushRock"), 0, settingsFilename);
static int configAlternativeMaxForceRightSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightSFRushRock"), 100, settingsFilename);
static int configFeedbackLengthSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthSFRushRock"), 120, settingsFilename);
static int PowerModeSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeSFRushRock"), 0, settingsFilename);
static int EnableForceSpringEffectSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectSFRushRock"), 0, settingsFilename);
static int ForceSpringStrengthSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthSFRushRock"), 0, settingsFilename);
static int EnableDamperSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperSFRushRock"), 0, settingsFilename);
static int DamperStrengthSFRushRock = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthSFRushRock"), 100, settingsFilename);

static int configMinForceCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceCrusnWld"), 0, settingsFilename);
static int configMaxForceCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceCrusnWld"), 100, settingsFilename);
static int configAlternativeMinForceLeftCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftCrusnWld"), 0, settingsFilename);
static int configAlternativeMaxForceLeftCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftCrusnWld"), 100, settingsFilename);
static int configAlternativeMinForceRightCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightCrusnWld"), 0, settingsFilename);
static int configAlternativeMaxForceRightCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightCrusnWld"), 100, settingsFilename);
static int configFeedbackLengthCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthCrusnWld"), 120, settingsFilename);
static int PowerModeCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeCrusnWld"), 0, settingsFilename);
static int EnableForceSpringEffectCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectCrusnWld"), 0, settingsFilename);
static int ForceSpringStrengthCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthCrusnWld"), 0, settingsFilename);
static int EnableDamperCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperCrusnWld"), 0, settingsFilename);
static int DamperStrengthCrusnWld = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthCrusnWld"), 100, settingsFilename);

static int configMinForceOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceOffRoadC"), 0, settingsFilename);
static int configMaxForceOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceOffRoadC"), 100, settingsFilename);
static int configAlternativeMinForceLeftOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftOffRoadC"), 0, settingsFilename);
static int configAlternativeMaxForceLeftOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftOffRoadC"), 100, settingsFilename);
static int configAlternativeMinForceRightOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightOffRoadC"), 0, settingsFilename);
static int configAlternativeMaxForceRightOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightOffRoadC"), 100, settingsFilename);
static int configFeedbackLengthOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthOffRoadC"), 120, settingsFilename);
static int PowerModeOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeOffRoadC"), 0, settingsFilename);
static int EnableForceSpringEffectOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectOffRoadC"), 0, settingsFilename);
static int ForceSpringStrengthOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthOffRoadC"), 0, settingsFilename);
static int EnableDamperOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperOffRoadC"), 0, settingsFilename);
static int DamperStrengthOffRoadC = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthOffRoadC"), 100, settingsFilename);

static int configMinForceCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceCrusnUSA"), 0, settingsFilename);
static int configMaxForceCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceCrusnUSA"), 100, settingsFilename);
static int configAlternativeMinForceLeftCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftCrusnUSA"), 0, settingsFilename);
static int configAlternativeMaxForceLeftCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftCrusnUSA"), 100, settingsFilename);
static int configAlternativeMinForceRightCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightCrusnUSA"), 0, settingsFilename);
static int configAlternativeMaxForceRightCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightCrusnUSA"), 100, settingsFilename);
static int configFeedbackLengthCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthCrusnUSA"), 120, settingsFilename);
static int PowerModeCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeCrusnUSA"), 0, settingsFilename);
static int EnableForceSpringEffectCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectCrusnUSA"), 0, settingsFilename);
static int ForceSpringStrengthCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthCrusnUSA"), 0, settingsFilename);
static int EnableDamperCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperCrusnUSA"), 0, settingsFilename);
static int DamperStrengthCrusnUSA = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthCrusnUSA"), 100, settingsFilename);

static int configMinForceCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceCalSpeed"), 0, settingsFilename);
static int configMaxForceCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceCalSpeed"), 100, settingsFilename);
static int configAlternativeMinForceLeftCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftCalSpeed"), 0, settingsFilename);
static int configAlternativeMaxForceLeftCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftCalSpeed"), 100, settingsFilename);
static int configAlternativeMinForceRightCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightCalSpeed"), 0, settingsFilename);
static int configAlternativeMaxForceRightCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightCalSpeed"), 100, settingsFilename);
static int configFeedbackLengthCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthCalSpeed"), 120, settingsFilename);
static int PowerModeCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeCalSpeed"), 0, settingsFilename);
static int EnableForceSpringEffectCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectCalSpeed"), 0, settingsFilename);
static int ForceSpringStrengthCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthCalSpeed"), 0, settingsFilename);
static int EnableDamperCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperCalSpeed"), 0, settingsFilename);
static int DamperStrengthCalSpeed = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthCalSpeed"), 100, settingsFilename);

static int configMinForceSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceSFRush2049"), 0, settingsFilename);
static int configMaxForceSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceSFRush2049"), 100, settingsFilename);
static int configAlternativeMinForceLeftSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftSFRush2049"), 0, settingsFilename);
static int configAlternativeMaxForceLeftSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftSFRush2049"), 100, settingsFilename);
static int configAlternativeMinForceRightSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightSFRush2049"), 0, settingsFilename);
static int configAlternativeMaxForceRightSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightSFRush2049"), 100, settingsFilename);
static int configFeedbackLengthSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthSFRush2049"), 120, settingsFilename);
static int PowerModeSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeSFRush2049"), 0, settingsFilename);
static int EnableForceSpringEffectSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectSFRush2049"), 0, settingsFilename);
static int ForceSpringStrengthSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthSFRush2049"), 0, settingsFilename);
static int EnableDamperSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperSFRush2049"), 0, settingsFilename);
static int DamperStrengthSFRush2049 = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthSFRush2049"), 100, settingsFilename);

static int configMinForceHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceHardD"), 0, settingsFilename);
static int configMaxForceHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceHardD"), 100, settingsFilename);
static int configAlternativeMinForceLeftHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftHardD"), 0, settingsFilename);
static int configAlternativeMaxForceLeftHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftHardD"), 100, settingsFilename);
static int configAlternativeMinForceRightHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightHardD"), 0, settingsFilename);
static int configAlternativeMaxForceRightHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightHardD"), 100, settingsFilename);
static int configFeedbackLengthHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthHardD"), 120, settingsFilename);
static int PowerModeHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeHardD"), 0, settingsFilename);
static int EnableForceSpringEffectHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectHardD"), 0, settingsFilename);
static int ForceSpringStrengthHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthHardD"), 0, settingsFilename);
static int EnableDamperHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperHardD"), 0, settingsFilename);
static int DamperStrengthHardD = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthHardD"), 100, settingsFilename);

static int configMinForceORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceORunners"), 0, settingsFilename);
static int configMaxForceORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceORunners"), 100, settingsFilename);
static int configAlternativeMinForceLeftORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftORunners"), 0, settingsFilename);
static int configAlternativeMaxForceLeftORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftORunners"), 100, settingsFilename);
static int configAlternativeMinForceRightORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightORunners"), 0, settingsFilename);
static int configAlternativeMaxForceRightORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightORunners"), 100, settingsFilename);
static int configMinForceORunnersDevice2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceORunnersDevice2"), 0, settingsFilename);
static int configMaxForceORunnersDevice2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceORunnersDevice2"), 100, settingsFilename);
static int configAlternativeMinForceLeftORunnersDevice2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftORunnersDevice2"), 0, settingsFilename);
static int configAlternativeMaxForceLeftORunnersDevice2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftORunnersDevice2"), 100, settingsFilename);
static int configAlternativeMinForceRightORunnersDevice2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightORunnersDevice2"), 0, settingsFilename);
static int configAlternativeMaxForceRightORunnersDevice2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightORunnersDevice2"), 100, settingsFilename);
static int configFeedbackLengthORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthORunners"), 120, settingsFilename);
static int EnableForceSpringEffectORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectORunners"), 0, settingsFilename);
static int ForceSpringStrengthORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthORunners"), 0, settingsFilename);
static int SinePeriodORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodORunners"), 0, settingsFilename);
static int SineFadePeriodORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodORunners"), 0, settingsFilename);
static int SineStrengthORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthORunners"), 0, settingsFilename);
static int RumbleStrengthLeftMotorORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorORunners"), 0, settingsFilename);
static int RumbleStrengthRightMotorORunners = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorORunners"), 0, settingsFilename);

static int configMinForceTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceTOutrun"), 0, settingsFilename);
static int configMaxForceTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceTOutrun"), 100, settingsFilename);
static int configAlternativeMinForceLeftTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftTOutrun"), 0, settingsFilename);
static int configAlternativeMaxForceLeftTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftTOutrun"), 100, settingsFilename);
static int configAlternativeMinForceRightTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightTOutrun"), 0, settingsFilename);
static int configAlternativeMaxForceRightTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightTOutrun"), 100, settingsFilename);
static int configFeedbackLengthTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthTOutrun"), 120, settingsFilename);
static int EnableForceSpringEffectTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectTOutrun"), 0, settingsFilename);
static int ForceSpringStrengthTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthTOutrun"), 0, settingsFilename);
static int SinePeriodTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodTOutrun"), 0, settingsFilename);
static int SineFadePeriodTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodTOutrun"), 0, settingsFilename);
static int SineStrengthTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthTOutrun"), 0, settingsFilename);
static int RumbleStrengthLeftMotorTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorTOutrun"), 0, settingsFilename);
static int RumbleStrengthRightMotorTOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorTOutrun"), 0, settingsFilename);

static int configMinForceCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceCBombers"), 0, settingsFilename);
static int configMaxForceCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceCBombers"), 100, settingsFilename);
static int configAlternativeMinForceLeftCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftCBombers"), 0, settingsFilename);
static int configAlternativeMaxForceLeftCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftCBombers"), 100, settingsFilename);
static int configAlternativeMinForceRightCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightCBombers"), 0, settingsFilename);
static int configAlternativeMaxForceRightCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightCBombers"), 100, settingsFilename);
static int configFeedbackLengthCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthCBombers"), 120, settingsFilename);
static int EnableForceSpringEffectCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectCBombers"), 0, settingsFilename);
static int ForceSpringStrengthCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthCBombers"), 0, settingsFilename);
static int SinePeriodCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodCBombers"), 0, settingsFilename);
static int SineFadePeriodCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodCBombers"), 0, settingsFilename);
static int SineStrengthCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthCBombers"), 0, settingsFilename);
static int RumbleStrengthLeftMotorCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorCBombers"), 0, settingsFilename);
static int RumbleStrengthRightMotorCBombers = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorCBombers"), 0, settingsFilename);

static int configMinForceOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceOutrun"), 0, settingsFilename);
static int configMaxForceOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceOutrun"), 100, settingsFilename);
static int configAlternativeMinForceLeftOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftOutrun"), 0, settingsFilename);
static int configAlternativeMaxForceLeftOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftOutrun"), 100, settingsFilename);
static int configAlternativeMinForceRightOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightOutrun"), 0, settingsFilename);
static int configAlternativeMaxForceRightOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightOutrun"), 100, settingsFilename);
static int configFeedbackLengthOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthOutrun"), 120, settingsFilename);
static int EnableForceSpringEffectOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectOutrun"), 0, settingsFilename);
static int ForceSpringStrengthOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthOutrun"), 0, settingsFilename);
static int SinePeriodOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodOutrun"), 0, settingsFilename);
static int SineFadePeriodOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodOutrun"), 0, settingsFilename);
static int SineStrengthOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthOutrun"), 0, settingsFilename);
static int RumbleStrengthLeftMotorOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorOutrun"), 0, settingsFilename);
static int RumbleStrengthRightMotorOutrun = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorOutrun"), 0, settingsFilename);

static int configMinForcePDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForcePDrift"), 0, settingsFilename);
static int configMaxForcePDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForcePDrift"), 100, settingsFilename);
static int configAlternativeMinForceLeftPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftPDrift"), 0, settingsFilename);
static int configAlternativeMaxForceLeftPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftPDrift"), 100, settingsFilename);
static int configAlternativeMinForceRightPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightPDrift"), 0, settingsFilename);
static int configAlternativeMaxForceRightPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightPDrift"), 100, settingsFilename);
static int configFeedbackLengthPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthPDrift"), 120, settingsFilename);
static int EnableForceSpringEffectPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectPDrift"), 0, settingsFilename);
static int ForceSpringStrengthPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthPDrift"), 0, settingsFilename);
static int SinePeriodPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodPDrift"), 0, settingsFilename);
static int SineFadePeriodPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodPDrift"), 0, settingsFilename);
static int SineStrengthPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthPDrift"), 0, settingsFilename);
static int RumbleStrengthLeftMotorPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorPDrift"), 0, settingsFilename);
static int RumbleStrengthRightMotorPDrift = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorPDrift"), 0, settingsFilename);

static int configMinForceDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceDAxle"), 0, settingsFilename);
static int configMaxForceDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceDAxle"), 100, settingsFilename);
static int configAlternativeMinForceLeftDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftDAxle"), 0, settingsFilename);
static int configAlternativeMaxForceLeftDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftDAxle"), 100, settingsFilename);
static int configAlternativeMinForceRightDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightDAxle"), 0, settingsFilename);
static int configAlternativeMaxForceRightDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightDAxle"), 100, settingsFilename);
static int configFeedbackLengthDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthDAxle"), 120, settingsFilename);
static int EnableForceSpringEffectDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectDAxle"), 0, settingsFilename);
static int ForceSpringStrengthDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthDAxle"), 0, settingsFilename);
static int SinePeriodDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodDAxle"), 0, settingsFilename);
static int SineFadePeriodDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodDAxle"), 0, settingsFilename);
static int SineStrengthDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthDAxle"), 0, settingsFilename);
static int RumbleStrengthLeftMotorDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorDAxle"), 0, settingsFilename);
static int RumbleStrengthRightMotorDAxle = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorDAxle"), 0, settingsFilename);

static int configMinForceAfterBurner2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceAfterBurner2"), 0, settingsFilename);
static int configMaxForceAfterBurner2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceAfterBurner2"), 100, settingsFilename);
static int RumbleStrengthLeftMotorAfterBurner2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorAfterBurner2"), 0, settingsFilename);
static int RumbleStrengthRightMotorAfterBurner2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorAfterBurner2"), 0, settingsFilename);

static int configMinForceCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceCisHeat"), 0, settingsFilename);
static int configMaxForceCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceCisHeat"), 100, settingsFilename);
static int configAlternativeMinForceLeftCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftCisHeat"), 0, settingsFilename);
static int configAlternativeMaxForceLeftCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftCisHeat"), 100, settingsFilename);
static int configAlternativeMinForceRightCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightCisHeat"), 0, settingsFilename);
static int configAlternativeMaxForceRightCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightCisHeat"), 100, settingsFilename);
static int configFeedbackLengthCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthCisHeat"), 120, settingsFilename);
static int EnableForceSpringEffectCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectCisHeat"), 0, settingsFilename);
static int ForceSpringStrengthCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthCisHeat"), 0, settingsFilename);
static int SinePeriodCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodCisHeat"), 0, settingsFilename);
static int SineFadePeriodCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodCisHeat"), 0, settingsFilename);
static int SineStrengthCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthCisHeat"), 0, settingsFilename);
static int RumbleStrengthLeftMotorCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorCisHeat"), 0, settingsFilename);
static int RumbleStrengthRightMotorCisHeat = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorCisHeat"), 0, settingsFilename);

static int configMinForceF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceF1GpStar"), 0, settingsFilename);
static int configMaxForceF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceF1GpStar"), 100, settingsFilename);
static int configAlternativeMinForceLeftF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftF1GpStar"), 0, settingsFilename);
static int configAlternativeMaxForceLeftF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftF1GpStar"), 100, settingsFilename);
static int configAlternativeMinForceRightF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightF1GpStar"), 0, settingsFilename);
static int configAlternativeMaxForceRightF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightF1GpStar"), 100, settingsFilename);
static int configFeedbackLengthF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthF1GpStar"), 120, settingsFilename);
static int EnableForceSpringEffectF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectF1GpStar"), 0, settingsFilename);
static int ForceSpringStrengthF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthF1GpStar"), 0, settingsFilename);
static int SinePeriodF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodF1GpStar"), 0, settingsFilename);
static int SineFadePeriodF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodF1GpStar"), 0, settingsFilename);
static int SineStrengthF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthF1GpStar"), 0, settingsFilename);
static int RumbleStrengthLeftMotorF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorF1GpStar"), 0, settingsFilename);
static int RumbleStrengthRightMotorF1GpStar = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorF1GpStar"), 0, settingsFilename);

static int configMinForceF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceF1GpStar2"), 0, settingsFilename);
static int configMaxForceF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceF1GpStar2"), 100, settingsFilename);
static int configAlternativeMinForceLeftF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftF1GpStar2"), 0, settingsFilename);
static int configAlternativeMaxForceLeftF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftF1GpStar2"), 100, settingsFilename);
static int configAlternativeMinForceRightF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightF1GpStar2"), 0, settingsFilename);
static int configAlternativeMaxForceRightF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightF1GpStar2"), 100, settingsFilename);
static int configFeedbackLengthF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthF1GpStar2"), 120, settingsFilename);
static int EnableForceSpringEffectF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectF1GpStar2"), 0, settingsFilename);
static int ForceSpringStrengthF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthF1GpStar2"), 0, settingsFilename);
static int SinePeriodF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("SinePeriodF1GpStar2"), 0, settingsFilename);
static int SineFadePeriodF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineFadePeriodF1GpStar2"), 0, settingsFilename);
static int SineStrengthF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("SineStrengthF1GpStar2"), 0, settingsFilename);
static int RumbleStrengthLeftMotorF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthLeftMotorF1GpStar2"), 0, settingsFilename);
static int RumbleStrengthRightMotorF1GpStar2 = GetPrivateProfileInt(TEXT("Settings"), TEXT("RumbleStrengthRightMotorF1GpStar2"), 0, settingsFilename);

static int configMinForceHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceHyperDrive"), 0, settingsFilename);
static int configMaxForceHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceHyperDrive"), 100, settingsFilename);
static int configAlternativeMinForceLeftHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftHyperDrive"), 0, settingsFilename);
static int configAlternativeMaxForceLeftHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftHyperDrive"), 100, settingsFilename);
static int configAlternativeMinForceRightHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightHyperDrive"), 0, settingsFilename);
static int configAlternativeMaxForceRightHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightHyperDrive"), 100, settingsFilename);
static int configFeedbackLengthHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthHyperDrive"), 120, settingsFilename);
static int EnableForceSpringEffectHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectHyperDrive"), 0, settingsFilename);
static int ForceSpringStrengthHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthHyperDrive"), 0, settingsFilename);
static int EnableDamperHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperHyperDrive"), 0, settingsFilename);
static int DamperStrengthHyperDrive = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthHyperDrive"), 100, settingsFilename);

static int configMinForceVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceVaporTrx"), 0, settingsFilename);
static int configMaxForceVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceVaporTrx"), 100, settingsFilename);
static int configAlternativeMinForceLeftVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftVaporTrx"), 0, settingsFilename);
static int configAlternativeMaxForceLeftVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftVaporTrx"), 100, settingsFilename);
static int configAlternativeMinForceRightVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightVaporTrx"), 0, settingsFilename);
static int configAlternativeMaxForceRightVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightVaporTrx"), 100, settingsFilename);
static int configFeedbackLengthVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthVaporTrx"), 120, settingsFilename);
static int EnableForceSpringEffectVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectVaporTrx"), 0, settingsFilename);
static int ForceSpringStrengthVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthVaporTrx"), 0, settingsFilename);
static int EnableDamperVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperVaporTrx"), 0, settingsFilename);
static int DamperStrengthVaporTrx = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthVaporTrx"), 100, settingsFilename);

static int configMinForceRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceRaveRacer"), 0, settingsFilename);
static int configMaxForceRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceRaveRacer"), 100, settingsFilename);
static int configAlternativeMinForceLeftRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftRaveRacer"), 0, settingsFilename);
static int configAlternativeMaxForceLeftRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftRaveRacer"), 100, settingsFilename);
static int configAlternativeMinForceRightRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightRaveRacer"), 0, settingsFilename);
static int configAlternativeMaxForceRightRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightRaveRacer"), 100, settingsFilename);
static int PowerModeRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeRaveRacer"), 0, settingsFilename);
static int configFeedbackLengthRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthRaveRacer"), 120, settingsFilename);
static int EnableForceSpringEffectRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectRaveRacer"), 0, settingsFilename);
static int ForceSpringStrengthRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthRaveRacer"), 0, settingsFilename);
static int EnableDamperRaveRacer= GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperRaveRacer"), 0, settingsFilename);
static int DamperStrengthRaveRacer = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthRaveRacer"), 100, settingsFilename);

static int configMinForceSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceSuperChase"), 0, settingsFilename);
static int configMaxForceSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceSuperChase"), 100, settingsFilename);
static int configAlternativeMinForceLeftSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftSuperChase"), 0, settingsFilename);
static int configAlternativeMaxForceLeftSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftSuperChase"), 100, settingsFilename);
static int configAlternativeMinForceRightSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightSuperChase"), 0, settingsFilename);
static int configAlternativeMaxForceRightSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightSuperChase"), 100, settingsFilename);
static int PowerModeSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeSuperChase"), 0, settingsFilename);
static int configFeedbackLengthSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthSuperChase"), 120, settingsFilename);
static int EnableForceSpringEffectSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectSuperChase"), 0, settingsFilename);
static int ForceSpringStrengthSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthSuperChase"), 0, settingsFilename);
static int EnableDamperSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperSuperChase"), 0, settingsFilename);
static int DamperStrengthSuperChase = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthSuperChase"), 100, settingsFilename);

static int configMinForceDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceDirtDash"), 0, settingsFilename);
static int configMaxForceDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceDirtDash"), 100, settingsFilename);
static int configAlternativeMinForceLeftDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftDirtDash"), 0, settingsFilename);
static int configAlternativeMaxForceLeftDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftDirtDash"), 100, settingsFilename);
static int configAlternativeMinForceRightDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightDirtDash"), 0, settingsFilename);
static int configAlternativeMaxForceRightDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightDirtDash"), 100, settingsFilename);
static int PowerModeDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeDirtDash"), 0, settingsFilename);
static int configFeedbackLengthDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthDirtDash"), 120, settingsFilename);
static int EnableForceSpringEffectDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectDirtDash"), 0, settingsFilename);
static int ForceSpringStrengthDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthDirtDash"), 0, settingsFilename);
static int FFBDivideDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("FFBDivideDirtDash"), 0, settingsFilename);
static int EnableDamperDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperDirtDash"), 0, settingsFilename);
static int DamperStrengthDirtDash = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthDirtDash"), 100, settingsFilename);

static int configMinForceAceDriverVictory= GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceAceDriverVictory"), 0, settingsFilename);
static int configMaxForceAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceAceDriverVictory"), 100, settingsFilename);
static int configAlternativeMinForceLeftAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftAceDriverVictory"), 0, settingsFilename);
static int configAlternativeMaxForceLeftAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftAceDriverVictory"), 100, settingsFilename);
static int configAlternativeMinForceRightAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightAceDriverVictory"), 0, settingsFilename);
static int configAlternativeMaxForceRightAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightAceDriverVictory"), 100, settingsFilename);
static int PowerModeAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeAceDriverVictory"), 0, settingsFilename);
static int configFeedbackLengthAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthAceDriverVictory"), 120, settingsFilename);
static int EnableForceSpringEffectAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectAceDriverVictory"), 0, settingsFilename);
static int ForceSpringStrengthAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthAceDriverVictory"), 0, settingsFilename);
static int FFBDivideAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("FFBDivideAceDriverVictory"), 0, settingsFilename);
static int EnableDamperAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperAceDriverVictory"), 0, settingsFilename);
static int DamperStrengthAceDriverVictory = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthAceDriverVictory"), 100, settingsFilename);

static int configMinForceAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("MinForceAceDriver"), 0, settingsFilename);
static int configMaxForceAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("MaxForceAceDriver"), 100, settingsFilename);
static int configAlternativeMinForceLeftAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceLeftAceDriver"), 0, settingsFilename);
static int configAlternativeMaxForceLeftAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceLeftAceDriver"), 100, settingsFilename);
static int configAlternativeMinForceRightAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMinForceRightAceDriver"), 0, settingsFilename);
static int configAlternativeMaxForceRightAceDriver= GetPrivateProfileInt(TEXT("Settings"), TEXT("AlternativeMaxForceRightAceDriver"), 100, settingsFilename);
static int PowerModeAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("PowerModeAceDriver"), 0, settingsFilename);
static int configFeedbackLengthAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("FeedbackLengthAceDriver"), 120, settingsFilename);
static int EnableForceSpringEffectAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableForceSpringEffectAceDriver"), 0, settingsFilename);
static int ForceSpringStrengthAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("ForceSpringStrengthAceDriver"), 0, settingsFilename);
static int FFBDivideAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("FFBDivideAceDriver"), 0, settingsFilename);
static int EnableDamperAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("EnableDamperAceDriver"), 0, settingsFilename);
static int DamperStrengthAceDriver = GetPrivateProfileInt(TEXT("Settings"), TEXT("DamperStrengthAceDriver"), 100, settingsFilename);

static bool init = false;
static bool initSpring = false;
static bool EmuName = false;
static bool RomGameName = false;
static bool Effect1 = false;
static bool Effect2 = false;
static bool Effect3 = false;
static bool DontSineUntilRaceStart = false;
static bool HardDrivinFrame = false;
static bool Motion = false;
static bool MotionFalse = false;
static bool StartEffectOnce = false;
static bool PatternFind = false;
static bool Scan = false;
static bool ScanFirstBootDelay = false;
static bool PatternLaunch = false;

HINSTANCE hInstance;
HINSTANCE hPrevInstance;
LPSTR lpCmdLine;
int nCmdShow;

static const char* FlycastnameFFB;
const char* nameFFB;
const char* EmulatorName;
char* name;
char* romname;
char* RunningFFB;
char* Emulator;
int vals[5] = { 0 };
int state4 = 0;
int state3 = 0;
int state2 = 0;
int state1 = 0;
int state0 = 0;
int frame = 0;
int HardDrivinFFB;
int StopConstant;
int newstateFFB;
int oldstateFFB;
int EffectCount;
int stateFFB;
int stateFFB2;
int stateFFB3;
int stateFFBDevice2;
int stateFFBDevice3;
int SineEffectState;
double Divide;
static INT_PTR FFBAddress;
static UINT8 ff;

std::string wheelA("wheel");

static int raveracer(int ffRaw);
static int acedrivertable(int ffRaw);
int SwapDirection(int direction);

static void FFBGameEffects(EffectConstants* constants, Helpers* helpers, EffectTriggers* triggers, int stateFFB, LPCSTR name)
{
	if (RunningFFB == NamcoFFBNew) // Ace Driver
	{
		if (name == mcuout3)
		{
			if (newstateFFB == 0)
			{
				if (UseConstantInf)
				{
					triggers->ConstantInf(constants->DIRECTION_FROM_LEFT, 0.0);
					triggers->ConstantInf(constants->DIRECTION_FROM_RIGHT, 0.0);
				}
				else
				{
					triggers->Constant(constants->DIRECTION_FROM_LEFT, 0.0);
					triggers->Constant(constants->DIRECTION_FROM_RIGHT, 0.0);
				}
			}
		}

		if (name == wheel_motor)
		{
			int fface = acedrivertable((UINT8)stateFFB);

			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			if (fface > 0)
			{
				double percentForce = fface / 62.0;

				triggers->Rumble(percentForce, 0.0, 100);
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
		
			else if (fface < 0)
			{
				double percentForce = (-fface) / 62.0;

				triggers->Rumble(0.0, percentForce, 100);
				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
			
			else
			{
				sendConstant(constants->DIRECTION_FROM_LEFT, 0.0);
				sendConstant(constants->DIRECTION_FROM_RIGHT, 0.0);
			}
		}
	}


	if (RunningFFB == RaveRacerNew) // Rave Racer
	{
		if (name == mcuout3)
		{
			if (newstateFFB == 0)
			{
				if (UseConstantInf)
				{
					triggers->ConstantInf(constants->DIRECTION_FROM_LEFT, 0.0);
					triggers->ConstantInf(constants->DIRECTION_FROM_RIGHT, 0.0);
				}
				else
				{
					triggers->Constant(constants->DIRECTION_FROM_LEFT, 0.0);
					triggers->Constant(constants->DIRECTION_FROM_RIGHT, 0.0);
				}
			}
		}
		if (name == wheel_motor)
		{
			UINT8 ffrave = raveracer((UINT8)stateFFB);

			auto sendConstant = [&](int direction, double strength)
				{
					direction = SwapDirection(direction);

					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};
			if ((ffrave > 0x3D) && (ffrave < 0x7C))
			{
				double percentForce = (124 - ffrave) / 61.0;

				triggers->Rumble(percentForce, 0.0, 100);
				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
			else if ((ffrave > 0x00) && (ffrave < 0x3E))
			{
				double percentForce = ffrave / 61.0;

				triggers->Rumble(0.0, percentForce, 100);
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
		}
	}

	if (RunningFFB == VirtuaRacingActive) //Virtua Racing
	{
		if (name == digit0)
		{
			// Umschalter für Constant / ConstantInf
			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			helpers->log("got value: ");
			std::string ffs = std::to_string(stateFFB);
			helpers->log((char*)ffs.c_str());

			if ((stateFFB == 0x03) || (stateFFB == 0x07) || (stateFFB == 0x09) || (stateFFB == 0x10))
			{
				if (stateFFB == 0x07)
					DontSineUntilRaceStart = true;
				if (stateFFB == 0x09)
					DontSineUntilRaceStart = false;

				double percentForce = 0.8;
				triggers->Spring(percentForce);

				// Stop Constant (egal welche Variante)
				sendConstant(constants->DIRECTION_FROM_LEFT, 0.0);
			}

			if (stateFFB == 0x20 || stateFFB == 0x28) //Clutch
			{
				double percentForce = 0.4;
				triggers->Friction(percentForce);

				sendConstant(constants->DIRECTION_FROM_LEFT, 0.0);
			}

			if (stateFFB > 0x2F && stateFFB < 0x40) //Centering
			{
				double percentForce = (stateFFB - 47) / 11.0;
				triggers->Spring(percentForce);

				sendConstant(constants->DIRECTION_FROM_LEFT, 0.0);
			}

			if (stateFFB == 0x40 || stateFFB == 0x46 || stateFFB == 0x4A) //Uncentering
			{
				if (stateFFB == 0x40)
				{
					double percentForce = 0.4;
					triggers->Rumble(percentForce, percentForce, 100);
					triggers->Sine(70, 30, percentForce);
				}
				else
				{
					if (DontSineUntilRaceStart)
					{
						double percentForce = 0.4;
						triggers->Rumble(percentForce, percentForce, 100);
						triggers->Sine(70, 30, percentForce);
					}
				}

				sendConstant(constants->DIRECTION_FROM_LEFT, 0.0);
			}

			if (stateFFB == 0x50 || stateFFB == 0x5F) //Roll Left
			{
				double percentForce = 0.5;
				triggers->Rumble(0, percentForce, 100);

				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
			else if (stateFFB == 0x60 || stateFFB == 0x6F) //Roll Right
			{
				double percentForce = 0.5;
				triggers->Rumble(percentForce, 0, 100);

				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
			else if (stateFFB != 0x50 && stateFFB != 0x5F && stateFFB != 0x60 && stateFFB != 0x6F)
			{
				// Stop Constant
				sendConstant(constants->DIRECTION_FROM_LEFT, 0.0);
			}
		}
	}

	if (RunningFFB == RacingFullValueActive1) // Mame games using all values 
	{
		if (name == wheel || name == wheel_motor)
		{
			// Umschalter für Constant / ConstantInf
			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			helpers->log("got value: ");
			std::string ffs = std::to_string(stateFFB);
			helpers->log((char*)ffs.c_str());

			if (stateFFB > 0x80 && stateFFB < 0x100)  // LEFT FORCE
			{
				double percentForce = (256 - stateFFB) / 126.0;
				double percentLength = 100;

				triggers->Rumble(percentForce, 0, percentLength);
				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
			else if (stateFFB > 0x00 && stateFFB < 0x80)  // RIGHT FORCE
			{
				double percentForce = (stateFFB) / 126.0;
				double percentLength = 100;

				triggers->Rumble(0, percentForce, percentLength);
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
		}
	}

	if (RunningFFB == RacingFullValueActive2) // Mame games using all values (reverse direction to above)
	{
		if (name == wheel)
		{
			// Umschalter für Constant / ConstantInf
			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			helpers->log("got value: ");
			std::string ffs = std::to_string(stateFFB);
			helpers->log((char*)ffs.c_str());

			if (stateFFB > 0x80 && stateFFB < 0x100)
			{
				double percentForce = (256 - stateFFB) / 126.0;
				double percentLength = 100;

				// reversed rumble direction
				triggers->Rumble(0, percentForce, percentLength);

				// reversed constant direction
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
			else if (stateFFB > 0x00 && stateFFB < 0x80)
			{
				double percentForce = (stateFFB) / 126.0;
				double percentLength = 100;

				triggers->Rumble(percentForce, 0, percentLength);

				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
		}
	}

	if (RunningFFB == srallynew) // Mame games using all values
	{
		if (name == wheel_motor)
		{
			// Umschalter für Constant / ConstantInf
			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			helpers->log("got value: ");
			std::string ffs = std::to_string(stateFFB);
			helpers->log((char*)ffs.c_str());

			// -----------------------------------------
			//  HARD STOP ON ZERO
			// -----------------------------------------
			if (stateFFB == 0x00)
			{
				triggers->Rumble(0, 0, 0);

				if (UseConstantInf)
				{
					triggers->ConstantInf(constants->DIRECTION_FROM_LEFT, 0.0);
					triggers->ConstantInf(constants->DIRECTION_FROM_RIGHT, 0.0);
				}
				else
				{
					triggers->Constant(constants->DIRECTION_FROM_LEFT, 0.0);
					triggers->Constant(constants->DIRECTION_FROM_RIGHT, 0.0);
				}

				return;
			}

			// -----------------------------------------
			//  Force FROM RIGHT (makes wheel move LEFT)
			//  Range: 0xC0 – 0xDF  (192 – 223)
			// -----------------------------------------
			if (stateFFB >= 0xC0 && stateFFB <= 0xDF)
			{
				double percentForce = (stateFFB - 0xC0) / 31.0;
				double percentLength = 100;

				triggers->Rumble(0, percentForce, percentLength);
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}

			// -----------------------------------------
			//  Force FROM LEFT (makes wheel move RIGHT)
			//  Range: 0x80 – 0x9F  (128 – 159)
			// -----------------------------------------
			else if (stateFFB >= 0x80 && stateFFB <= 0x9F)
			{
				double percentForce = (stateFFB - 0x80) / 31.0;
				double percentLength = 100;

				triggers->Rumble(percentForce, 0, percentLength);
				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
		}
	}

	if (RunningFFB == Konami)
	{
		if (name == wheel || name == wheel_motor || name == pcboutput0 || name == output0 || name == wheel0)
		{
			// Umschalter für Constant / ConstantInf
			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			helpers->log("got value: ");
			std::string ffs = std::to_string(stateFFB);
			helpers->log((char*)ffs.c_str());

			// 0x80–0x8F = rechts
			if (stateFFB > 0x7F && stateFFB < 0x90)
			{
				double percentForce = (stateFFB - 127) / 16.0;
				double percentLength = 100;

				triggers->Rumble(0, percentForce, percentLength);
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
			// 0x90–0x9F = links
			else if (stateFFB > 0x8F && stateFFB < 0xA0)
			{
				double percentForce = (stateFFB - 143) / 16.0;
				double percentLength = 100;

				triggers->Rumble(percentForce, 0, percentLength);
				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
		}
	}

	if (RunningFFB == hng64)
	{
		if (name == wheel_motor)
		{
			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			helpers->log("got value: ");
			std::string ffs = std::to_string(stateFFB);
			helpers->log((char*)ffs.c_str());

			if (stateFFB >= 193 && stateFFB <= 255)
			{
				double percentForce = (stateFFB - 193) / 62.0;
				double percentLength = 100;

				triggers->Rumble(0, percentForce, percentLength);
				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
	
			else if (stateFFB >= 129 && stateFFB <= 191)
			{
				double percentForce = (stateFFB - 129) / 62.0;
				double percentLength = 100;

				triggers->Rumble(percentForce, 0, percentLength);
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
		}
	}

	if (RunningFFB == m2new) // Mame games using all values 
	{
		if (name == wheel_motor)
		{
			// Umschalter für Constant / ConstantInf
			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			helpers->log("got value: ");
			std::string ffs = std::to_string(stateFFB);
			helpers->log((char*)ffs.c_str());

			// SPRING
			if ((stateFFB > 0x09) && (stateFFB < 0x18))
			{
				double percentForce = (stateFFB - 15) / 8.0;
				triggers->Spring(percentForce);
			}

			// CLUTCH
			if ((stateFFB > 0x1F) && (stateFFB < 0x28))
			{
				double percentForce = (stateFFB - 31) / 8.0;
				triggers->Friction(percentForce);
			}

			// CENTERING
			if ((stateFFB > 0x2F) && (stateFFB < 0x3D))
			{
				double percentForce = (stateFFB - 47) / 13.0;
				triggers->Spring(percentForce);
			}

			// UNCENTERING
			if ((stateFFB > 0x3F) && (stateFFB < 0x48))
			{
				double percentForce = (stateFFB - 63) / 8.0;
				triggers->Sine(40, 0, percentForce);
				triggers->Rumble(percentForce, percentForce, 100);
			}

			// ROLL LEFT
			if ((stateFFB > 0x4F) && (stateFFB < 0x58))
			{
				double percentForce = (stateFFB - 79) / 8.0;
				triggers->Rumble(0, percentForce, 100);
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
			// ROLL RIGHT
			else if ((stateFFB > 0x5F) && (stateFFB < 0x68))
			{
				double percentForce = (stateFFB - 95) / 8.0;
				triggers->Rumble(percentForce, 0, 100);
				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
			// NEUTRAL → Stop ConstantInf / Constant
			else
			{
				// Neutral: ConstantInf beenden durch Kraft = 0
				sendConstant(constants->DIRECTION_FROM_LEFT, 0.0);
			}
		}
	}

	if (RunningFFB == HardDrivinActive) // Hard Drivin
	{
		if (!HardDrivinFrame)
			HardDrivinFrame = true;

		// frame == 4 → FFB aktualisieren
		if (frame == 4)
		{
			HardDrivinFFB = (vals[0] & 15) + ((vals[3] & 7) << 5);

			if ((vals[1] & 0xF0) == 0xF0)
				HardDrivinFFB |= 0x10;

			if ((vals[2] & 0xF0) == 0xF0)
				HardDrivinFFB = -HardDrivinFFB;

			// Begrenzen auf [-100, 100]
			if (HardDrivinFFB > 100)
				HardDrivinFFB = 100;

			if (HardDrivinFFB < -100)
				HardDrivinFFB = -100;

			// Umschalter für Constant vs. ConstantInf
			auto sendConstant = [&](int direction, double strength)
				{
					if (UseConstantInf)
						triggers->ConstantInf(direction, strength);
					else
						triggers->Constant(direction, strength);
				};

			// FFB nach links
			if (HardDrivinFFB >= 0)
			{
				double percentForce = HardDrivinFFB / 100.0;
				double percentLength = 100;

				triggers->Rumble(percentForce, 0, percentLength);
				sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
			}
			// FFB nach rechts
			else
			{
				HardDrivinFFB = -HardDrivinFFB;
				double percentForce = HardDrivinFFB / 100.0;
				double percentLength = 100;

				triggers->Rumble(0, percentForce, percentLength);
				sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
			}
		}
	}
}

typedef int(__stdcall* MAME_START)(int hWnd);
typedef int(__stdcall* MAME_STOP)(void);
typedef int(__stdcall* MAME_COPYDATA)(int id, const char* name);
typedef int(__stdcall* MAME_UPDATESTATE)(const char* id, int state);
typedef int(__stdcall* MAME_OUTPUT)(const char* name, int value);
typedef int(__stdcall* INIT_MAME)(int clientid, PWCHAR name, MAME_START start, MAME_STOP stop, MAME_COPYDATA copydata, MAME_UPDATESTATE updatestate, MAME_OUTPUT output);

MAME_START mame_start_ptr;
MAME_STOP mame_stop_ptr;
MAME_COPYDATA mame_copydata_ptr;
MAME_UPDATESTATE mame_updatestate_ptr;
MAME_OUTPUT mame_output_ptr;
INIT_MAME dll_init;

int __stdcall mame_start(int hWnd);
int __stdcall mame_stop(void);
int __stdcall mame_copydata(int id, const char* name);
int __stdcall mame_updatestate(const char* id, int state);
int __stdcall mame_output(const char* name, int value);

void CallTheOutputs()
{
#ifdef _WIN64  
	ProcDLL = LoadLibrary(TEXT("MAME64.dll"));
#else  
	ProcDLL = LoadLibrary(TEXT("MAME32.dll"));
#endif
	if (ProcDLL != NULL)
	{
		dll_init = (INIT_MAME)GetProcAddress(ProcDLL, "init_mame");
	}
	else
	{
#ifdef _WIN64
		MessageBoxA(NULL, "MAME64.dll is missing!", "FFBPluginError", NULL);
#else
		MessageBoxA(NULL, "MAME32.dll is missing!", "FFBPluginError", NULL);
#endif
	}
}
static int(__stdcall* ExitOri)(UINT uExitCode);
static int __stdcall ExitHook(UINT uExitCode)
{
	TerminateProcess(GetCurrentProcess(), 0);
	return 0;
}

typedef struct _id_map_entry id_map_entry;
struct _id_map_entry
{
	id_map_entry* next;
	const char* name;
	WPARAM					id;
};

void AppendTextToEditCtrl(HWND hWnd, LPCTSTR lpString);
void reset_id_to_outname_cache(void);
const char* get_name_from_id(int id);
void add_map_entry(id_map_entry* entry, int id, char* name);

id_map_entry* idmaplist;

HWND hEdit;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void AppendTextToEditCtrl(HWND hWnd, LPCTSTR pszText);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CallTheOutputs();
	HWND hWnd;
	MSG msg;
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"MAMEInterop";
	wcex.hIconSm = NULL;

	RegisterClassEx(&wcex);

	hWnd = CreateWindow(L"MAMEInterop", L"MAMEInterop", WS_OVERLAPPEDWINDOW,
		0, 0, 512, 512, NULL, NULL, hInstance, NULL);

	if (hWnd == NULL)
		MessageBox(hWnd, L"Could not create window", L"Error", MB_OK | MB_ICONERROR);

	hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"",
		WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
		8, 8, 488, 464, hWnd, NULL, GetModuleHandle(NULL), NULL);

	if (hEdit == NULL)
		MessageBox(hWnd, L"Could not create edit box.", L"Error", MB_OK | MB_ICONERROR);

	if (hWnd != NULL)
	{
		//ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}
	
	mame_start_ptr = mame_start;
	mame_stop_ptr = mame_stop;
	mame_copydata_ptr = mame_copydata;
	mame_updatestate_ptr = mame_updatestate;
	mame_output_ptr = mame_output;

	dll_init(0, L"Test", mame_start_ptr, mame_stop_ptr, mame_copydata_ptr, mame_updatestate_ptr, mame_output_ptr);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		reset_id_to_outname_cache();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void AppendTextToEditCtrl(HWND hWnd, LPCTSTR lpString)
{
	int iPrevLen = GetWindowTextLength(hWnd);
	SendMessage(hWnd, EM_SETSEL, iPrevLen, iPrevLen);
	SendMessage(hWnd, EM_REPLACESEL, 0, (LPARAM)lpString);
}

void reset_id_to_outname_cache(void)
{
	while (idmaplist != NULL)
	{
		id_map_entry* temp = idmaplist;
		idmaplist = temp->next;
		free(temp);
	}
}

const char* get_name_from_id(int id)
{
	while (idmaplist != NULL)
	{
		id_map_entry* temp = idmaplist;

		if (temp->id == (WPARAM)id)
			return temp->name;

		idmaplist = temp->next;
	}

	return NULL;
}

void add_map_entry(id_map_entry* entry, int id, char* name)
{
	char* string;

	entry = (id_map_entry*)malloc(sizeof(entry));
	string = (char*)malloc(strlen(name) + 1);

	if (entry != NULL && string != NULL)
	{
		entry->next = idmaplist;
		entry->name = string;
		entry->id = id;

		strcpy(string, name);
		idmaplist = entry;
	}
}

int __stdcall mame_start(int hWnd)
{
	WCHAR buf[256];

	wsprintf(buf, L"mame_start hwnd = 0x%08x\r\n", hWnd);

	AppendTextToEditCtrl(hEdit, buf);

	return 1;
}

int __stdcall mame_stop(void)
{
	reset_id_to_outname_cache();

	AppendTextToEditCtrl(hEdit, TEXT("mame_stop\r\n"));

	StopConstant = 255;

	return 1;
}

static void removeWord(char* str, char* toRemove)
{
	int i, j, stringLen, toRemoveLen;
	int found;

	stringLen = strlen(str);
	toRemoveLen = strlen(toRemove);


	for (i = 0; i <= stringLen - toRemoveLen; i++)
	{
		found = 1;
		for (j = 0; j < toRemoveLen; j++)
		{
			if (str[i + j] != toRemove[j])
			{
				found = 0;
				break;
			}
		}

		if (str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0')
		{
			found = 0;
		}


		if (found == 1)
		{
			for (j = i; j <= stringLen - toRemoveLen; j++)
			{
				str[j] = str[j + toRemoveLen];
			}

			stringLen = stringLen - toRemoveLen;

			i--;
		}
	}
}

int __stdcall mame_copydata(int id, const char* name)
{
	WCHAR buf[256];

	wsprintf(buf, L"id %d = '%S'\r\n", id, name);

	if (id == 0)
	{
		sprintf(GameName, "%s", name);

		removeWord(GameName, "game =");

		int whitespace = 0;

		for (int i = 0; i < strlen(GameName); i++)
		{
			if (GameName[i] == ' ' || GameName[i] == '\t')
				whitespace++;
			else
				break;
		}

		for (int i = 0; i < strlen(GameName); i++)
		{
			if (i + whitespace < strlen(GameName))
				GameName[i] = GameName[i + whitespace];
			else
				GameName[i] = 0;
		}
	}

	AppendTextToEditCtrl(hEdit, buf);

	return 1;
}

int __stdcall mame_updatestate(const char* id, int state)
{
	WCHAR buf[256];

	LPCSTR name = get_name_from_id((int)id);

	if (name == NULL)
		name = id;

	wsprintf(buf, L"updatestate: id=%d (%S) state=%d\r\n", id, name, state);
	AppendTextToEditCtrl(hEdit, buf);

	CStringA stringName(name);
	nameFFB = stringName;

	newstateFFB = state;

	if (HardDrivinFrame)
	{
		if (name == wheelA)
		{
			state3 = state2;
			state2 = state1;
			state1 = state0;
			state0 = state;

			//detect 0xE0 and 0x00 
			boolean stop = false;
			if ((state == 0xE0 && state1 == 0x00 && state2 == 0xE0 && state3 == 0x00) || 
				(state == 0x00 && state1 == 0xE0 && state2 == 0x00 && state3 == 0xE0)) 
			{
				stop = true;
				frame = 0;
			}
			if (frame > 4) {
				frame = 0;
			}
			//vals[0] should always be < 200. vals[1] should always be > 200. If not, the state is invalid, start over. 
			if (frame > 2 && (vals[0] > 200 || (vals[1] < 200 && vals[1] != 0))) {
				frame = 0;
				vals[1] = 0;
				vals[2] = 0;
				vals[3] = 0;
			}

			//if (!(((state == 0xE0) || (state == 0)) && ((frame == 0) || (frame == 4))))
			//if ((state != 0xE0) && (state != 0x00))
			if(!stop)
			{
				vals[frame] = state;
				frame++;
			}
		}
	}

	if (RomGameName && RunningFFB > 0)
		FFBGameEffects(myconstants, myhelpers, mytriggers, state, name);
	
	return 1;
}

int __stdcall mame_output(const char* name, int value)
{
	WCHAR buf[256];

	wsprintf(buf, L"output: name=%S value=%d\r\n", name, value);
	AppendTextToEditCtrl(hEdit, buf);

	return 1;
}

static DWORD WINAPI ScanThread(LPVOID lpParam)
{
	if (romname == superchs || romname == superchsj || romname == superchsp || romname == superchsu) //Super Chase Criminal Termination
	{
		aAddy2 = PatternScan("\x80\x38\x00\x50\x49\x5A\x05\x70\x11\x01\x4B\x54\x4F", "xxxxxxxxxxxxx");
	}

	if (romname == dirtdash || romname == dirtdasha || romname == dirtdashj || romname == acedrvrw || romname == acedrive || romname == victlapw || romname == victlap) //Dirt Dash, Ace Driver & Ace Driver Victory Lap
	{
		aAddy2 = PatternScan("\xC8\x00\xC8\x00\xC8\x00\xC8\x00\xC8\x00\xC8\x00\xC8\x00\xC8\x00\x14\x00\x14\x00\x14\x00\x14\x00\x14\x00\x14\x00\x14\x00\x14", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	}

	return 0;
}

static int raveracer(int ffRaw)
{
	static const int map[256] = {
		/* 0x00 */ -1, -1, 62, -1, 30, -1, 94, -1,
		/* 0x08 */ 46, -1, 78, -1, 14, -1, 110, -1,
		/* 0x10 */ 54, -1, 70, -1, 22, -1, 102, -1,
		/* 0x18 */ 38, -1, 86, -1, 6,  -1, 118, -1,
		/* 0x20 */ 59, -1, 65, -1, 27, -1, 97, -1,
		/* 0x28 */ 43, -1, 81, -1, 11, -1, 113, -1,
		/* 0x30 */ 50, -1, 74, -1, 18, -1, 106, -1,
		/* 0x38 */ 34, -1, 90, -1, 2,  -1, 122, -1,
		/* 0x40 */ 60, -1, 64, -1, 28, -1, 96, -1,
		/* 0x48 */ 44, -1, 80, -1, 12, -1, 112, -1,
		/* 0x50 */ 52, -1, 72, -1, 20, -1, 104, -1,
		/* 0x58 */ 36, -1, 88, -1, 4,  -1, 120, -1,
		/* 0x60 */ 56, -1, 68, -1, 24, -1, 100, -1,
		/* 0x68 */ 40, -1, 84, -1, 8,  -1, 116, -1,
		/* 0x70 */ 48, -1, 76, -1, 16, -1, 108, -1,
		/* 0x78 */ 32, -1, 92, -1, 1,  -1, 123, -1,
		/* 0x80 */ 61, -1, 63, -1, 29, -1, 95, -1,
		/* 0x88 */ 45, -1, 79, -1, 13, -1, 111, -1,
		/* 0x90 */ 53, -1, 71, -1, 21, -1, 103, -1,
		/* 0x98 */ 37, -1, 87, -1, 5,  -1, 119, -1,
		/* 0xA0 */ 57, -1, 67, -1, 25, -1, 99,  -1,
		/* 0xA8 */ 41, -1, 83, -1, 9,  -1, 115, -1,
		/* 0xB0 */ 49, -1, 75, -1, 17, -1, 107, -1,
		/* 0xB8 */ 33, -1, 91, -1, -1, -1, -1, -1,
		/* 0xC0 */ 58, -1, 66, -1, 26, -1, 98,  -1,
		/* 0xC8 */ 42, -1, 82, -1, 10, -1, 114, -1,
		/* 0xD0 */ 51, -1, 73, -1, 19, -1, 105, -1,
		/* 0xD8 */ 35, -1, 89, -1, 3,  -1, 121, -1,
		/* 0xE0 */ 55, -1, 69, -1, 23, -1, 101, -1,
		/* 0xE8 */ 39, -1, 85, -1, 7,  -1, 117, -1,
		/* 0xF0 */ 47, -1, 77, -1, 15, -1, 109, -1,
		/* 0xF8 */ 31, -1, 93, -1, -1, -1, -1, -1
	};

	return map[ffRaw & 0xFF];
}

static int acedrivertable(int ffRaw)
{
	static const int map[256] = {
		/* 0x00 */  0,   62,  0,  -62,  0,   31,  0,  -31,
		/* 0x08 */  0,   47,  0,  -47,  0,   15,  0,  -15,
		/* 0x10 */  0,   55,  0,  -55,  0,   23,  0,  -23,
		/* 0x18 */  0,   39,  0,  -39,  0,    7,  0,   -7,
		/* 0x20 */  0,   59,  0,  -59,  0,   27,  0,  -27,
		/* 0x28 */  0,   43,  0,  -43,  0,   11,  0,  -11,
		/* 0x30 */  0,   51,  0,  -51,  0,   19,  0,  -19,
		/* 0x38 */  0,   35,  0,  -35,  0,    3,  0,   -3,

		/* 0x40 */  0,   61,  0,  -61,  0,   29,  0,  -29,
		/* 0x48 */  0,   45,  0,  -45,  0,   13,  0,  -13,
		/* 0x50 */  0,   53,  0,  -53,  0,   21,  0,  -21,
		/* 0x58 */  0,   37,  0,  -37,  0,    5,  0,   -5,
		/* 0x60 */  0,   57,  0,  -57,  0,   25,  0,  -25,
		/* 0x68 */  0,   41,  0,  -41,  0,    9,  0,   -9,
		/* 0x70 */  0,   49,  0,  -49,  0,   17,  0,  -17,
		/* 0x78 */  0,   33,  0,  -33,  0,    1,  0,   -1,

		/* 0x80 */  0,   62,  0,  -62,  0,   30,  0,  -30,
		/* 0x88 */  0,   46,  0,  -46,  0,   14,  0,  -14,
		/* 0x90 */  0,   54,  0,  -54,  0,   22,  0,  -22,
		/* 0x98 */  0,   38,  0,  -38,  0,    6,  0,   -6,
		/* 0xA0 */  0,   58,  0,  -58,  0,   26,  0,  -26,
		/* 0xA8 */  0,   42,  0,  -42,  0,   10,  0,  -10,
		/* 0xB0 */  0,   50,  0,  -50,  0,   18,  0,  -18,
		/* 0xB8 */  0,   34,  0,  -34,  0,    2,  0,   -2,

		/* 0xC0 */  0,   60,  0,  -60,  0,   28,  0,  -28,
		/* 0xC8 */  0,   44,  0,  -44,  0,   12,  0,  -12,
		/* 0xD0 */  0,   52,  0,  -52,  0,   20,  0,  -20,
		/* 0xD8 */  0,   36,  0,  -36,  0,    4,  0,   -4,
		/* 0xE0 */  0,   56,  0,  -56,  0,   24,  0,  -24,
		/* 0xE8 */  0,   40,  0,  -40,  0,    8,  0,   -8,
		/* 0xF0 */  0,   48,  0,  -48,  0,   16,  0,  -16,
		/* 0xF8 */  0,   32,  0,  -32,  0,    0,  0,    0  // 0xFF = true neutral
	};
	return map[ffRaw & 0xFF];
}

DWORD WINAPI ThreadForOutputs(LPVOID lpParam)
{
	WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	return 0;
}

DWORD WINAPI ThreadForDaytonaStartEffect(LPVOID lpParam)
{
	Sleep(1300);
	Effect2 = false;
	return 0;
}

int SwapDirection(int direction)
{
	// Wenn INI-Schalter aus: nichts ändern
	if (!ReverseDirection)
		return direction;

	// Falls constants noch nicht initialisiert sind, lieber nichts kaputt machen
	if (!myconstants)
		return direction;

	// Echte IDs aus EffectConstants benutzen
	if (direction == myconstants->DIRECTION_FROM_LEFT)
		return myconstants->DIRECTION_FROM_RIGHT;

	if (direction == myconstants->DIRECTION_FROM_RIGHT)
		return myconstants->DIRECTION_FROM_LEFT;

	// Alles andere unverändert lassen (z.B. NEUTRAL etc.)
	return direction;
}

void MAMESupermodel::FFBLoop(EffectConstants* constants, Helpers* helpers, EffectTriggers* triggers) {

	myconstants = constants;
	myhelpers = helpers;
	mytriggers = triggers;

	if (!init)
	{
		wchar_t* deviceGUIDString2 = new wchar_t[256];
		int Device2GUID = GetPrivateProfileString(TEXT("Settings"), TEXT("Device2GUID"), NULL, deviceGUIDString2, 256, settingsFilename);
		char joystick_guid[256];
		sprintf(joystick_guid, "%S", deviceGUIDString2);
		SDL_JoystickGUID guid, dev_guid;
		int numJoysticks = SDL_NumJoysticks();
		std::string njs = std::to_string(numJoysticks);
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			extern int joystick1Index;
			if (i == joystick1Index)
			{
				continue;
			}
			SDL_Joystick* js2 = SDL_JoystickOpen(i);
			SDL_JoystickGUID guid = SDL_JoystickGetGUID(js2);
			char guid_str[1024];
			SDL_JoystickGetGUIDString(guid, guid_str, sizeof(guid_str));
			const char* name = SDL_JoystickName(js2);
			char text[256];
			sprintf(text, "Joystick: %d / Name: %s / GUID: %s\n", i, name, guid_str);
			guid = SDL_JoystickGetGUIDFromString(joystick_guid);
			dev_guid = SDL_JoystickGetGUID(js2);
			if (!memcmp(&guid, &dev_guid, sizeof(SDL_JoystickGUID)))
			{
				GameController2 = SDL_JoystickOpen(i);
				joystick_index2 = SDL_JoystickInstanceID(GameController2);
				ControllerHaptic2 = SDL_HapticOpenFromJoystick(GameController2);
				break;
			}
			SDL_JoystickClose(js2);
		}
		haptic2 = ControllerHaptic2;
		if ((SDL_HapticRumbleSupported(haptic2) == SDL_TRUE))
		{
			SDL_HapticRumbleInit;
			SDL_HapticRumbleInit(ControllerHaptic2);
		}
		SDL_HapticSetGain(haptic2, 100);

		wchar_t* deviceGUIDString3 = new wchar_t[256];
		int Device3GUID = GetPrivateProfileString(TEXT("Settings"), TEXT("Device3GUID"), NULL, deviceGUIDString3, 256, settingsFilename);
		char joystick_guid2[256];
		sprintf(joystick_guid2, "%S", deviceGUIDString3);
		SDL_JoystickGUID guid2, dev_guid2;
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			extern int joystick1Index;
			if (i == joystick1Index)
			{
				continue;
			}
			SDL_Joystick* js3 = SDL_JoystickOpen(i);
			SDL_JoystickGUID guid2 = SDL_JoystickGetGUID(js3);
			char guid_str2[1024];
			SDL_JoystickGetGUIDString(guid2, guid_str2, sizeof(guid_str2));
			const char* name2 = SDL_JoystickName(js3);
			char text2[256];
			sprintf(text2, "Joystick: %d / Name: %s / GUID: %s\n", i, name2, guid_str2);
			guid2 = SDL_JoystickGetGUIDFromString(joystick_guid2);
			dev_guid2 = SDL_JoystickGetGUID(js3);
			if (!memcmp(&guid2, &dev_guid2, sizeof(SDL_JoystickGUID)))
			{
				GameController3 = SDL_JoystickOpen(i);
				joystick_index3 = SDL_JoystickInstanceID(GameController3);
				ControllerHaptic3 = SDL_HapticOpenFromJoystick(GameController3);
				break;
			}
			SDL_JoystickClose(js3);
		}
		haptic3 = ControllerHaptic3;
		if ((SDL_HapticRumbleSupported(haptic3) == SDL_TRUE))
		{
			SDL_HapticRumbleInit;
			SDL_HapticRumbleInit(ControllerHaptic3);
		}
		SDL_HapticSetGain(haptic3, 100);

		if (configGameId == 60)
		{
			MH_Initialize();
			MH_CreateHookApi(L"KERNEL32.dll", "ExitProcess", ExitHook, (void**)&ExitOri);
			MH_EnableHook(MH_ALL_HOOKS);
		}
		init = true;
	}

	if (EnableForceSpringEffect)
	{
		triggers->Springi(ForceSpringStrength / 100.0);
	}

	romname = new char[256]; //name of rom being played
	sprintf(romname, "%s", GameName);

	name = new char[256]; //name of FFB currently
	sprintf(name, "%s", nameFFB);

	if (!RomGameName)
	{
		if (romname != NULL)
		{
			//Select code to run via rom name

			if (romname == cartfury)
			{
				configMinForce = configMinForceCartFury;
				configMaxForce = configMaxForceCartFury;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftCartFury;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftCartFury;
				configAlternativeMinForceRight = configAlternativeMinForceRightCartFury;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightCartFury;
				configFeedbackLength = configFeedbackLengthCartFury;
				PowerMode = PowerModeCartFury;
				EnableForceSpringEffect = EnableForceSpringEffectCartFury;
				ForceSpringStrength = ForceSpringStrengthCartFury;
				EnableDamper = EnableDamperCartFury;
				DamperStrength = DamperStrengthCartFury;

				RunningFFB = "RacingFullValueActive1";
			}

			if (romname == overrev || romname == overrevba || romname == overrevb)
			{
				configMinForce = configMinForceOverRev;
				configMaxForce = configMaxForceOverRev;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftOverRev;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftOverRev;
				configAlternativeMinForceRight = configAlternativeMinForceRightOverRev;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightOverRev;
				configFeedbackLength = configFeedbackLengthOverRev;
				PowerMode = PowerModeOverRev;
				EnableForceSpringEffect = EnableForceSpringEffectOverRev;
				ForceSpringStrength = ForceSpringStrengthOverRev;
				EnableDamper = EnableDamperOverRev;
				DamperStrength = DamperStrengthOverRev;

				RunningFFB = "m2new";
			}

			if (romname == vr)
			{
				configMinForce = configMinForceVirtuaRacing;
				configMaxForce = configMaxForceVirtuaRacing;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftVirtuaRacing;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftVirtuaRacing;
				configAlternativeMinForceRight = configAlternativeMinForceRightVirtuaRacing;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightVirtuaRacing;
				configFeedbackLength = configFeedbackLengthVirtuaRacing;
				EnableForceSpringEffect = EnableForceSpringEffectVirtuaRacing;
				ForceSpringStrength = ForceSpringStrengthVirtuaRacing;
				EnableDamper = EnableDamperVirtuaRacing;
				DamperStrength = DamperStrengthVirtuaRacing;

				RunningFFB = "VirtuaRacingActive";
			}

			if (romname == roadedge)
			{
				configMinForce = configMinForceRoadEdge;
				configMaxForce = configMaxForceRoadEdge;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftRoadEdge;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftRoadEdge;
				configAlternativeMinForceRight = configAlternativeMinForceRightRoadEdge;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightRoadEdge;
				configFeedbackLength = configFeedbackLengthRoadEdge;
				PowerMode = PowerModeRoadEdge;
				EnableForceSpringEffect = EnableForceSpringEffectRoadEdge;
				ForceSpringStrength = ForceSpringStrengthRoadEdge;
				EnableDamper = EnableDamperRoadEdge;
				DamperStrength = DamperStrengthRoadEdge;

				RunningFFB = "hng64";
			}

			if (romname == xrally)
			{
				configMinForce = configMinForceXRally;
				configMaxForce = configMaxForceXRally;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftXRally;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftXRally;
				configAlternativeMinForceRight = configAlternativeMinForceRightXRally;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightXRally;
				configFeedbackLength = configFeedbackLengthXRally;
				PowerMode = PowerModeXRally;
				EnableForceSpringEffect = EnableForceSpringEffectXRally;
				ForceSpringStrength = ForceSpringStrengthXRally;
				EnableDamper = EnableDamperXRally;
				DamperStrength = DamperStrengthXRally;

				RunningFFB = "hng64";
			}

			if (romname == thrilld || romname == thrillda || romname == thrilldj || romname == thrillde)
			{
				configMinForce = configMinForceThrillD;
				configMaxForce = configMaxForceThrillD;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftThrillD;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftThrillD;
				configAlternativeMinForceRight = configAlternativeMinForceRightThrillD;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightThrillD;
				configFeedbackLength = configFeedbackLengthThrillD;
				PowerMode = PowerModeThrillD;
				EnableForceSpringEffect = EnableForceSpringEffectThrillD;
				ForceSpringStrength = ForceSpringStrengthThrillD;
				EnableDamper = EnableDamperThrillD;
				DamperStrength = DamperStrengthThrillD;

				RunningFFB = "Konami";
			}

			if (romname == windheat || romname == windheata || romname == windheatj || romname == windheatu)
			{
				configMinForce = configMinForceWindheat;
				configMaxForce = configMaxForceWindheat;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftWindheat;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftWindheat;
				configAlternativeMinForceRight = configAlternativeMinForceRightWindheat;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightWindheat;
				configFeedbackLength = configFeedbackLengthWindheat;
				PowerMode = PowerModeWindheat;
				EnableForceSpringEffect = EnableForceSpringEffectWindheat;
				ForceSpringStrength = ForceSpringStrengthWindheat;
				EnableDamper = EnableDamperWindheat;
				DamperStrength = DamperStrengthWindheat;

				RunningFFB = "Konami";
			}

			if (romname == gticlub || romname == gticluba || romname == gticlubj || romname == gticlubu)
			{
				configMinForce = configMinForceGTIClub;
				configMaxForce = configMaxForceGTIClub;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftGTIClub;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftGTIClub;
				configAlternativeMinForceRight = configAlternativeMinForceRightGTIClub;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightGTIClub;
				configFeedbackLength = configFeedbackLengthGTIClub;
				PowerMode = PowerModeGTIClub;
				EnableForceSpringEffect = EnableForceSpringEffectGTIClub;
				ForceSpringStrength = ForceSpringStrengthGTIClub;
				EnableDamper = EnableDamperGTIClub;
				DamperStrength = DamperStrengthGTIClub;

				RunningFFB = "Konami";
			}
			if (romname == midnrun || romname == midnruna || romname == midnrunj || romname == midnruna2)
			{
				configMinForce = configMinForceMidnRun;
				configMaxForce = configMaxForceMidnRun;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftMidnRun;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftMidnRun;
				configAlternativeMinForceRight = configAlternativeMinForceRightMidnRun;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightMidnRun;
				configFeedbackLength = configFeedbackLengthMidnRun;
				PowerMode = PowerModeMidnRun;
				EnableForceSpringEffect = EnableForceSpringEffectMidnRun;
				ForceSpringStrength = ForceSpringStrengthMidnRun;
				EnableDamper = EnableDamperMidnRun;
				DamperStrength = DamperStrengthMidnRun;

				RunningFFB = "Konami";
			}

			if (romname == racingj || romname == racingja || romname == racingje || romname == racingjj || romname == racingju)
			{
				configMinForce = configMinForceRacingJ;
				configMaxForce = configMaxForceRacingJ;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftRacingJ;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftRacingJ;
				configAlternativeMinForceRight = configAlternativeMinForceRightRacingJ;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightRacingJ;
				configFeedbackLength = configFeedbackLengthRacingJ;
				PowerMode = PowerModeRacingJ;
				EnableForceSpringEffect = EnableForceSpringEffectRacingJ;
				ForceSpringStrength = ForceSpringStrengthRacingJ;
				EnableDamper = EnableDamperRacingJ;
				DamperStrength = DamperStrengthRacingJ;

				RunningFFB = "Konami";
			}

			if (romname == racingj2 || romname == racingj2a || romname == racingj2e || romname == racingj2j || romname == racingj2u)
			{
				configMinForce = configMinForceRacingJ2;
				configMaxForce = configMaxForceRacingJ2;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftRacingJ2;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftRacingJ2;
				configAlternativeMinForceRight = configAlternativeMinForceRightRacingJ2;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightRacingJ2;
				configFeedbackLength = configFeedbackLengthRacingJ2;
				PowerMode = PowerModeRacingJ2;
				EnableForceSpringEffect = EnableForceSpringEffectRacingJ2;
				ForceSpringStrength = ForceSpringStrengthRacingJ2;
				EnableDamper = EnableDamperRacingJ2;
				DamperStrength = DamperStrengthRacingJ2;

				RunningFFB = "Konami";
			}

			if (romname == sfrush || romname == sfrusha)
			{
				configMinForce = configMinForceSFRush;
				configMaxForce = configMaxForceSFRush;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftSFRush;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftSFRush;
				configAlternativeMinForceRight = configAlternativeMinForceRightSFRush;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightSFRush;
				configFeedbackLength = configFeedbackLengthSFRush;
				PowerMode = PowerModeSFRush;
				EnableForceSpringEffect = EnableForceSpringEffectSFRush;
				ForceSpringStrength = ForceSpringStrengthSFRush;
				EnableDamper = EnableDamperSFRush;
				DamperStrength = DamperStrengthSFRush;

				RunningFFB = "RacingFullValueActive2";
			}

			if (romname == sfrushrk || romname == sfrushrkwo)
			{
				configMinForce = configMinForceSFRushRock;
				configMaxForce = configMaxForceSFRushRock;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftSFRushRock;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftSFRushRock;
				configAlternativeMinForceRight = configAlternativeMinForceRightSFRushRock;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightSFRushRock;
				configFeedbackLength = configFeedbackLengthSFRushRock;
				PowerMode = PowerModeSFRushRock;
				EnableForceSpringEffect = EnableForceSpringEffectSFRushRock;
				ForceSpringStrength = ForceSpringStrengthSFRushRock;
				EnableDamper = EnableDamperSFRushRock;
				DamperStrength = DamperStrengthSFRushRock;

				RunningFFB = "RacingFullValueActive2";
			}

			if (romname == crusnwld || romname == crusnwld24 || romname == crusnwld23 || romname == crusnwld20 || romname == crusnwld19 || romname == crusnwld17)
			{
				configMinForce = configMinForceCrusnWld;
				configMaxForce = configMaxForceCrusnWld;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftCrusnWld;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftCrusnWld;
				configAlternativeMinForceRight = configAlternativeMinForceRightCrusnWld;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightCrusnWld;
				configFeedbackLength = configFeedbackLengthCrusnWld;
				PowerMode = PowerModeCrusnWld;
				EnableForceSpringEffect = EnableForceSpringEffectCrusnWld;
				ForceSpringStrength = ForceSpringStrengthCrusnWld;
				EnableDamper = EnableDamperCrusnWld;
				DamperStrength = DamperStrengthCrusnWld;

				RunningFFB = "RacingFullValueActive2";
			}

			if (romname == superchs || romname == superchsj || romname == superchsp || romname == superchsu)
			{
				configMinForce = configMinForceSuperChase;
				configMaxForce = configMaxForceSuperChase;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftSuperChase;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftSuperChase;
				configAlternativeMinForceRight = configAlternativeMinForceRightSuperChase;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightSuperChase;
				configFeedbackLength = configFeedbackLengthSuperChase;
				PowerMode = PowerModeSuperChase;
				EnableForceSpringEffect = EnableForceSpringEffectSuperChase;
				ForceSpringStrength = ForceSpringStrengthSuperChase;
				EnableDamper = EnableDamperSuperChase;
				DamperStrength = DamperStrengthSuperChase;

				RunningFFB = "SuperChaseActive";
			}

			if (romname == offroadc || romname == offroadc4 || romname == offroadc3 || romname == offroadc1)
			{
				configMinForce = configMinForceOffRoadC;
				configMaxForce = configMaxForceOffRoadC;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftOffRoadC;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftOffRoadC;
				configAlternativeMinForceRight = configAlternativeMinForceRightOffRoadC;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightOffRoadC;
				configFeedbackLength = configFeedbackLengthOffRoadC;
				PowerMode = PowerModeOffRoadC;
				EnableForceSpringEffect = EnableForceSpringEffectOffRoadC;
				ForceSpringStrength = ForceSpringStrengthOffRoadC;
				EnableDamper = EnableDamperOffRoadC;
				DamperStrength = DamperStrengthOffRoadC;

				RunningFFB = "RacingFullValueActive2";
			}

			if (romname == crusnusa || romname == crusnusa40 || romname == crusnusa21)
			{
				configMinForce = configMinForceCrusnUSA;
				configMaxForce = configMaxForceCrusnUSA;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftCrusnUSA;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftCrusnUSA;
				configAlternativeMinForceRight = configAlternativeMinForceRightCrusnUSA;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightCrusnUSA;
				configFeedbackLength = configFeedbackLengthCrusnUSA;
				PowerMode = PowerModeCrusnUSA;
				EnableForceSpringEffect = EnableForceSpringEffectCrusnUSA;
				ForceSpringStrength = ForceSpringStrengthCrusnUSA;
				EnableDamper = EnableDamperCrusnUSA;
				DamperStrength = DamperStrengthCrusnUSA;

				RunningFFB = "RacingFullValueActive2";
			}

			if (romname == calspeed || romname == calspeeda || romname == calspeedb)
			{
				configMinForce = configMinForceCalSpeed;
				configMaxForce = configMaxForceCalSpeed;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftCalSpeed;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftCalSpeed;
				configAlternativeMinForceRight = configAlternativeMinForceRightCalSpeed;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightCalSpeed;
				configFeedbackLength = configFeedbackLengthCalSpeed;
				PowerMode = PowerModeCalSpeed;
				EnableForceSpringEffect = EnableForceSpringEffectCalSpeed;
				ForceSpringStrength = ForceSpringStrengthCalSpeed;
				EnableDamper = EnableDamperCalSpeed;
				DamperStrength = DamperStrengthCalSpeed;

				RunningFFB = "RacingFullValueActive1";
			}

			if (romname == sf2049 || romname == sf2049se || romname == sf2049te)
			{
				configMinForce = configMinForceSFRush2049;
				configMaxForce = configMaxForceSFRush2049;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftSFRush2049;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftSFRush2049;
				configAlternativeMinForceRight = configAlternativeMinForceRightSFRush2049;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightSFRush2049;
				configFeedbackLength = configFeedbackLengthSFRush2049;
				PowerMode = PowerModeSFRush2049;
				EnableForceSpringEffect = EnableForceSpringEffectSFRush2049;
				ForceSpringStrength = ForceSpringStrengthSFRush2049;
				EnableDamper = EnableDamperSFRush2049;
				DamperStrength = DamperStrengthSFRush2049;

				RunningFFB = "RacingFullValueActive1";
			}

			if (romname == harddriv1 || romname == harddrivb6 || romname == harddrivb || romname == harddrivg4 || romname == harddrivg || romname == harddrivj6 || romname == harddrivj ||
				romname == harddriv2 || romname == harddriv3 || romname == harddriv || romname == harddrivcb || romname == harddrivcg || romname == harddrivc1 || romname == harddrivc ||
				romname == hdrivairp || romname == hdrivair || romname == racedrivb1 || romname == racedrivb4 || romname == racedrivb || romname == racedrivg1 || romname == racedrivg4 ||
				romname == racedrivg || romname == racedriv1 || romname == racedriv2 || romname == racedriv3 || romname == racedriv4 || romname == racedriv || romname == racedrivcb4 || 
				romname == racedrivcb || romname == racedrivcg4 || romname == racedrivcg || romname == racedrivc2 || romname == racedrivc4 || romname == racedrivc || romname == racedrivpan)
			{
				configMinForce = configMinForceHardD;
				configMaxForce = configMaxForceHardD;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftHardD;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftHardD;
				configAlternativeMinForceRight = configAlternativeMinForceRightHardD;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightHardD;
				configFeedbackLength = configFeedbackLengthHardD;
				PowerMode = PowerModeHardD;
				EnableForceSpringEffect = EnableForceSpringEffectHardD;
				ForceSpringStrength = ForceSpringStrengthHardD;
				EnableDamper = EnableDamperHardD;
				DamperStrength = DamperStrengthHardD;

				RunningFFB = "HardDrivinActive";
			}

			if (romname == orunners || romname == orunnersu || romname == orunnersj)
			{
				configMinForce = configMinForceORunners;
				configMaxForce = configMaxForceORunners;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftORunners;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftORunners;
				configAlternativeMinForceRight = configAlternativeMinForceRightORunners;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightORunners;
				configMinForceDevice2 = configMinForceORunnersDevice2;
				configMaxForceDevice2 = configMaxForceORunnersDevice2;
				configAlternativeMinForceLeftDevice2 = configAlternativeMinForceLeftORunnersDevice2;
				configAlternativeMaxForceLeftDevice2 = configAlternativeMaxForceLeftORunnersDevice2;
				configAlternativeMinForceRightDevice2 = configAlternativeMinForceRightORunnersDevice2;
				configAlternativeMaxForceRightDevice2 = configAlternativeMaxForceRightORunnersDevice2;
				configFeedbackLength = configFeedbackLengthORunners;
				EnableForceSpringEffect = EnableForceSpringEffectORunners;
				ForceSpringStrength = ForceSpringStrengthORunners;
				SinePeriod = SinePeriodORunners;
				SineFadePeriod = SineFadePeriodORunners;
				SineStrength = SineStrengthORunners;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorORunners;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorORunners;

				RunningFFB = "RacingActive1";
			}

			if (romname == toutrun || romname == toutrund || romname == toutrunj || romname == toutrunjd)
			{
				configMinForce = configMinForceTOutrun;
				configMaxForce = configMaxForceTOutrun;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftTOutrun;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftTOutrun;
				configAlternativeMinForceRight = configAlternativeMinForceRightTOutrun;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightTOutrun;
				configFeedbackLength = configFeedbackLengthTOutrun;
				EnableForceSpringEffect = EnableForceSpringEffectTOutrun;
				ForceSpringStrength = ForceSpringStrengthTOutrun;
				SinePeriod = SinePeriodTOutrun;
				SineFadePeriod = SineFadePeriodTOutrun;
				SineStrength = SineStrengthTOutrun;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorTOutrun;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorTOutrun;

				RunningFFB = "RacingActive1";
			}

			if (romname == cbombers || romname == cbombersj || romname == cbombersp)
			{
				configMinForce = configMinForceCBombers;
				configMaxForce = configMaxForceCBombers;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftCBombers;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftCBombers;
				configAlternativeMinForceRight = configAlternativeMinForceRightCBombers;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightCBombers;
				configFeedbackLength = configFeedbackLengthCBombers;
				EnableForceSpringEffect = EnableForceSpringEffectCBombers;
				ForceSpringStrength = ForceSpringStrengthCBombers;
				SinePeriod = SinePeriodCBombers;
				SineFadePeriod = SineFadePeriodCBombers;
				SineStrength = SineStrengthCBombers;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorCBombers;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorCBombers;

				RunningFFB = "RacingActive1";
			}

			if (romname == outrunra || romname == outrun || romname == outruneh)
			{
				configMinForce = configMinForceOutrun;
				configMaxForce = configMaxForceOutrun;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftOutrun;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftOutrun;
				configAlternativeMinForceRight = configAlternativeMinForceRightOutrun;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightOutrun;
				configFeedbackLength = configFeedbackLengthOutrun;
				EnableForceSpringEffect = EnableForceSpringEffectOutrun;
				ForceSpringStrength = ForceSpringStrengthOutrun;
				SinePeriod = SinePeriodOutrun;
				SineFadePeriod = SineFadePeriodOutrun;
				SineStrength = SineStrengthOutrun;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorOutrun;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorOutrun;

				RunningFFB = "OutrunActive";
			}

			if (romname == pdrift || romname == pdrifta || romname == pdrifte || romname == pdriftj || romname == pdriftl)
			{
				configMinForce = configMinForcePDrift;
				configMaxForce = configMaxForcePDrift;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftPDrift;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftPDrift;
				configAlternativeMinForceRight = configAlternativeMinForceRightPDrift;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightPDrift;
				configFeedbackLength = configFeedbackLengthPDrift;
				EnableForceSpringEffect = EnableForceSpringEffectPDrift;
				ForceSpringStrength = ForceSpringStrengthPDrift;
				SinePeriod = SinePeriodPDrift;
				SineFadePeriod = SineFadePeriodPDrift;
				SineStrength = SineStrengthPDrift;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorPDrift;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorPDrift;

				RunningFFB = "PDriftActive";
			}

			if (romname == dblaxle || romname == dblaxleu)
			{
				configMinForce = configMinForceDAxle;
				configMaxForce = configMaxForceDAxle;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftDAxle;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftDAxle;
				configAlternativeMinForceRight = configAlternativeMinForceRightDAxle;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightDAxle;
				configFeedbackLength = configFeedbackLengthDAxle;
				EnableForceSpringEffect = EnableForceSpringEffectDAxle;
				ForceSpringStrength = ForceSpringStrengthDAxle;
				SinePeriod = SinePeriodDAxle;
				SineFadePeriod = SineFadePeriodDAxle;
				SineStrength = SineStrengthDAxle;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorDAxle;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorDAxle;

				RunningFFB = "RacingActive1";
			}

			if (romname == cischeat)
			{
				configMinForce = configMinForceCisHeat;
				configMaxForce = configMaxForceCisHeat;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftCisHeat;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftCisHeat;
				configAlternativeMinForceRight = configAlternativeMinForceRightCisHeat;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightCisHeat;
				configFeedbackLength = configFeedbackLengthCisHeat;
				EnableForceSpringEffect = EnableForceSpringEffectCisHeat;
				ForceSpringStrength = ForceSpringStrengthCisHeat;
				SinePeriod = SinePeriodCisHeat;
				SineFadePeriod = SineFadePeriodCisHeat;
				SineStrength = SineStrengthCisHeat;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorCisHeat;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorCisHeat;

				RunningFFB = "RacingActive2";
			}

			if (romname == f1gpstar || romname == f1gpstaro)
			{
				configMinForce = configMinForceF1GpStar;
				configMaxForce = configMaxForceF1GpStar;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftF1GpStar;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftF1GpStar;
				configAlternativeMinForceRight = configAlternativeMinForceRightF1GpStar;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightF1GpStar;
				configFeedbackLength = configFeedbackLengthF1GpStar;
				EnableForceSpringEffect = EnableForceSpringEffectF1GpStar;
				ForceSpringStrength = ForceSpringStrengthF1GpStar;
				SinePeriod = SinePeriodF1GpStar;
				SineFadePeriod = SineFadePeriodF1GpStar;
				SineStrength = SineStrengthF1GpStar;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorF1GpStar;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorF1GpStar;

				RunningFFB = "RacingActive2";
			}

			if (romname == f1gpstr2)
			{
				configMinForce = configMinForceF1GpStar2;
				configMaxForce = configMaxForceF1GpStar2;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftF1GpStar2;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftF1GpStar2;
				configAlternativeMinForceRight = configAlternativeMinForceRightF1GpStar2;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightF1GpStar2;
				configFeedbackLength = configFeedbackLengthF1GpStar2;
				EnableForceSpringEffect = EnableForceSpringEffectF1GpStar2;
				ForceSpringStrength = ForceSpringStrengthF1GpStar2;
				SinePeriod = SinePeriodF1GpStar2;
				SineFadePeriod = SineFadePeriodF1GpStar2;
				SineStrength = SineStrengthF1GpStar2;
				RumbleStrengthLeftMotor = RumbleStrengthLeftMotorF1GpStar2;
				RumbleStrengthRightMotor = RumbleStrengthRightMotorF1GpStar2;

				RunningFFB = "RacingActive2";
			}

			if (romname == hyprdriv)
			{
				configMinForce = configMinForceHyperDrive;
				configMaxForce = configMaxForceHyperDrive;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftHyperDrive;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftHyperDrive;
				configAlternativeMinForceRight = configAlternativeMinForceRightHyperDrive;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightHyperDrive;
				configFeedbackLength = configFeedbackLengthHyperDrive;
				EnableForceSpringEffect = EnableForceSpringEffectHyperDrive;
				ForceSpringStrength = ForceSpringStrengthHyperDrive;
				EnableDamper = EnableDamperHyperDrive;
				DamperStrength = DamperStrengthHyperDrive;
				
				RunningFFB = "RacingFullValueActive1";
			}

			if (romname == vaportrx || romname == vaportrp)
			{
				configMinForce = configMinForceVaporTrx;
				configMaxForce = configMaxForceVaporTrx;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftVaporTrx;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftVaporTrx;
				configAlternativeMinForceRight = configAlternativeMinForceRightVaporTrx;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightVaporTrx;
				configFeedbackLength = configFeedbackLengthVaporTrx;
				EnableForceSpringEffect = EnableForceSpringEffectVaporTrx;
				ForceSpringStrength = ForceSpringStrengthVaporTrx;
				EnableDamper = EnableDamperVaporTrx;
				DamperStrength = DamperStrengthVaporTrx;
				
				RunningFFB = "RacingFullValueActive1";
			}

			if (romname == raveracw || romname == raveracj || romname == raveracja || romname == raverace)
			{
				configMinForce = configMinForceRaveRacer;
				configMaxForce = configMaxForceRaveRacer;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftRaveRacer;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftRaveRacer;
				configAlternativeMinForceRight = configAlternativeMinForceRightRaveRacer;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightRaveRacer;
				configFeedbackLength = configFeedbackLengthRaveRacer;
				PowerMode = PowerModeRaveRacer;
				EnableForceSpringEffect = EnableForceSpringEffectRaveRacer;
				ForceSpringStrength = ForceSpringStrengthRaveRacer;
				EnableDamper = EnableDamperRaveRacer;
				DamperStrength = DamperStrengthRaveRacer;

				RunningFFB = "RaveRacerNew";
			}

			if (romname == daytona || romname == daytonas || romname == daytonase)
			{
				configMinForce = configMinForceDaytonaMAME;
				configMaxForce = configMaxForceDaytonaMAME;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftDaytonaMAME;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftDaytonaMAME;
				configAlternativeMinForceRight = configAlternativeMinForceRightDaytonaMAME;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightDaytonaMAME;
				configFeedbackLength = configFeedbackLengthDaytonaMAME;
				PowerMode = PowerModeDaytonaMAME;
				EnableForceSpringEffect = EnableForceSpringEffectDaytonaMAME;
				ForceSpringStrength = ForceSpringStrengthDaytonaMAME;
				EnableDamper = EnableDamperDaytonaMAME;
				DamperStrength = DamperStrengthDaytonaMAME;

				RunningFFB = "m2new";
			}

			if (romname == indy500 || romname == indy500d || romname == indy500to)
			{
				configMinForce = configMinForceIndy500MAME;
				configMaxForce = configMaxForceIndy500MAME;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftIndy500MAME;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftIndy500MAME;
				configAlternativeMinForceRight = configAlternativeMinForceRightIndy500MAME;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightIndy500MAME;
				configFeedbackLength = configFeedbackLengthIndy500MAME;
				PowerMode = PowerModeIndy500MAME;
				EnableForceSpringEffect = EnableForceSpringEffectIndy500MAME;
				ForceSpringStrength = ForceSpringStrengthIndy500MAME;
				EnableDamper = EnableDamperIndy500MAME;
				DamperStrength = DamperStrengthIndy500MAME;

				RunningFFB = "m2new";
			}

			if (romname == sgt24h)
			{
				configMinForce = configMinForceSuperGTMAME;
				configMaxForce = configMaxForceSuperGTMAME;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftSuperGTMAME;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftSuperGTMAME;
				configAlternativeMinForceRight = configAlternativeMinForceRightSuperGTMAME;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightSuperGTMAME;
				configFeedbackLength = configFeedbackLengthSuperGTMAME;
				PowerMode = PowerModeSuperGTMAME;
				EnableForceSpringEffect = EnableForceSpringEffectSuperGTMAME;
				ForceSpringStrength = ForceSpringStrengthSuperGTMAME;
				EnableDamper = EnableDamperSuperGTMAME;
				DamperStrength = DamperStrengthSuperGTMAME;

				RunningFFB = "m2new";
			}

			if (romname == srallyc || romname == srallycb || romname == srallycdx || romname == srallycdxa)
			{
				configMinForce = configMinForceSRallyMAME;
				configMaxForce = configMaxForceSRallyMAME;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftSRallyMAME;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftSRallyMAME;
				configAlternativeMinForceRight = configAlternativeMinForceRightSRallyMAME;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightSRallyMAME;
				configFeedbackLength = configFeedbackLengthSRallyMAME;
				PowerMode = PowerModeSRallyMAME;
				EnableForceSpringEffect = EnableForceSpringEffectSRallyMAME;
				ForceSpringStrength = ForceSpringStrengthSRallyMAME;
				EnableDamper = EnableDamperSRallyMAME;
				DamperStrength = DamperStrengthSRallyMAME;

				RunningFFB = "srallynew";
			}

			if (romname == dirtdash || romname == dirtdasha || romname == dirtdashj)
			{
				configMinForce = configMinForceDirtDash;
				configMaxForce = configMaxForceDirtDash;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftDirtDash;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftDirtDash;
				configAlternativeMinForceRight = configAlternativeMinForceRightDirtDash;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightDirtDash;
				configFeedbackLength = configFeedbackLengthDirtDash;
				PowerMode = PowerModeDirtDash;
				EnableForceSpringEffect = EnableForceSpringEffectDirtDash;
				ForceSpringStrength = ForceSpringStrengthDirtDash;
				Divide = FFBDivideDirtDash * 1.0;
				EnableDamper = EnableDamperDirtDash;
				DamperStrength = DamperStrengthDirtDash;

				RunningFFB = "NamcoFFBActive";
			}

			if (romname == stcc || romname == stcca || romname == stccb)
			{
				configMinForce = configMinForceSTCCMAME;
				configMaxForce = configMaxForceSTCCMAME;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftSTCCMAME;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftSTCCMAME;
				configAlternativeMinForceRight = configAlternativeMinForceRightSTCCMAME;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightSTCCMAME;
				configFeedbackLength = configFeedbackLengthSTCCMAME;
				PowerMode = PowerModeSTCCMAME;
				EnableForceSpringEffect = EnableForceSpringEffectSTCCMAME;
				ForceSpringStrength = ForceSpringStrengthSTCCMAME;
				EnableDamper = EnableDamperSTCCMAME;
				DamperStrength = DamperStrengthSTCCMAME;

				RunningFFB = "m2new";
			}

			if (romname == victlapw || romname == victlap)
			{
				configMinForce = configMinForceAceDriverVictory;
				configMaxForce = configMaxForceAceDriverVictory;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftAceDriverVictory;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftAceDriverVictory;
				configAlternativeMinForceRight = configAlternativeMinForceRightAceDriverVictory;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightAceDriverVictory;
				configFeedbackLength = configFeedbackLengthAceDriverVictory;
				PowerMode = PowerModeAceDriverVictory;
				EnableForceSpringEffect = EnableForceSpringEffectAceDriverVictory;
				ForceSpringStrength = ForceSpringStrengthAceDriverVictory;
				Divide = FFBDivideAceDriverVictory * 1.0;
				EnableDamper = EnableDamperAceDriverVictory;
				DamperStrength = DamperStrengthAceDriverVictory;

				RunningFFB = "NamcoFFBNew";
			}

			if (romname == acedrvrw || romname == acedrive)
			{
				configMinForce = configMinForceAceDriver;
				configMaxForce = configMaxForceAceDriver;
				configAlternativeMinForceLeft = configAlternativeMinForceLeftAceDriver;
				configAlternativeMaxForceLeft = configAlternativeMaxForceLeftAceDriver;
				configAlternativeMinForceRight = configAlternativeMinForceRightAceDriver;
				configAlternativeMaxForceRight = configAlternativeMaxForceRightAceDriver;
				configFeedbackLength = configFeedbackLengthAceDriver;
				PowerMode = PowerModeAceDriver;
				EnableForceSpringEffect = EnableForceSpringEffectAceDriver;
				ForceSpringStrength = ForceSpringStrengthAceDriver;
				Divide = FFBDivideAceDriver * 1.0;
				EnableDamper = EnableDamperAceDriver;
				DamperStrength = DamperStrengthAceDriver;

				RunningFFB = "NamcoFFBNew";
			}

			if (enableLogging)
			{
				char romnametext[256];
				sprintf(romnametext, "RomName = %s", romname);
				helpers->log(romnametext);

				char RunningFFBtext[256];
				sprintf(RunningFFBtext, "RunningFFB = %s", RunningFFB);
				helpers->log(RunningFFBtext);
			}

			if ((RunningFFB != NULL) && (RunningFFB[0] != '\0'))
				RomGameName = true;
		}
	}

	if (RomGameName && RunningFFB > 0)
	{
		if (RunningFFB > 0 && EnableDamper)
			triggers->Damper(DamperStrength / 100.0);

		if (RunningFFB == RacingActive1) //Outrunners,Turbo Outrun,CBombers,DAxle
		{
			if (name == MA_Steering_Wheel_motor || name == upright_wheel_motor || name == Vibration_motor || name == Wheel_vibration || name == Wheel_Vibration || name == genout2)
			{
				helpers->log("P1 value: ");
				std::string ffs = std::to_string(newstateFFB);
				helpers->log((char*)ffs.c_str());

				if (newstateFFB == 0)
				{
					Effect1 = false;
				}

				stateFFB = newstateFFB;
			}

			if (name == MB_Steering_Wheel_motor)
			{
				helpers->log("P2 value: ");
				std::string ffs = std::to_string(newstateFFB);
				helpers->log((char*)ffs.c_str());

				if (newstateFFB == 0)
				{
					Effect2 = false;
				}

				stateFFBDevice2 = newstateFFB;
			}

			if (stateFFB == 0x01)
			{
				Effect1 = true;
			}
			else
			{
				Effect1 = false;
			}

			if (stateFFBDevice2 == 0x01)
			{
				Effect2 = true;
			}
			else
			{
				Effect2 = false;
			}

			if (Effect1)
			{
				triggers->Sine(SinePeriod, SineFadePeriod, SineStrength / 100.0);
				triggers->Rumble(RumbleStrengthLeftMotor / 100.0, RumbleStrengthRightMotor / 100.0, 100);
			}

			if (!Effect1)
			{
				triggers->Sine(0, 0, 0);
				triggers->Rumble(0, 0, 0);
			}

			if (Effect2)
			{
				triggers->SineDevice2(SinePeriod, SineFadePeriod, SineStrength / 100.0);
				triggers->RumbleDevice2(RumbleStrengthLeftMotor / 100.0, RumbleStrengthRightMotor / 100.0, 100);
			}

			if (!Effect2)
			{
				triggers->SineDevice2(0, 0, 0);
				triggers->RumbleDevice2(0, 0, 0);
			}
		}

		if (RunningFFB == RacingActive2) //Cisco Heat,F1 GpStar //Keep seperate as names is led2 and could possibly interfere with other outputs
		{
			if (name == led2)
			{
				helpers->log("P1 value: ");
				std::string ffs = std::to_string(newstateFFB);
				helpers->log((char*)ffs.c_str());

				if (newstateFFB == 0)
				{
					Effect1 = false;
				}

				stateFFB = newstateFFB;
			}

			if (stateFFB == 0x01)
			{
				Effect1 = true;
			}
			else
			{
				Effect1 = false;
			}

			if (Effect1)
			{
				triggers->Sine(SinePeriod, SineFadePeriod, SineStrength / 100.0);
				triggers->Rumble(RumbleStrengthLeftMotor / 100.0, RumbleStrengthRightMotor / 100.0, 100);
			}

			if (!Effect1)
			{
				triggers->Sine(0, 0, 0);
				triggers->Rumble(0, 0, 0);
			}
		}

		if (RunningFFB == OutrunActive)
		{
			if (name == Bank_Motor_Direction)
			{
				helpers->log("got value: ");
				std::string ffs = std::to_string(newstateFFB);
				helpers->log((char*)ffs.c_str());

				if (newstateFFB != 0)
				{
					stateFFB = newstateFFB;
				}
			}

			if (name == Vibration_motor)
			{
				helpers->log("got value: ");
				std::string ffs = std::to_string(newstateFFB);
				helpers->log((char*)ffs.c_str());
				if (newstateFFB > 0)
				{

				}

				if (newstateFFB == 0)
				{
					Effect1 = false;
				}

				stateFFB2 = newstateFFB;
			}

			if (name == Bank_Motor_Speed)
			{
				stateFFB3 = newstateFFB;
			}

			if (Motion)
			{
				if (stateFFB == 0x01)
				{
					double percentForce = (1 + stateFFB3) / 8.0;
					triggers->Constant(constants->DIRECTION_FROM_LEFT, percentForce);
				}
				if (stateFFB == 0x02)
				{
					double percentForce = (1 + stateFFB3) / 8.0;
					triggers->Constant(constants->DIRECTION_FROM_RIGHT, percentForce);
				}
			}

			if (stateFFB == 1)
			{
				Motion = true;
				MotionFalse = false;
			}

			if (stateFFB2 == 1)
			{
				Motion = false;
			}

			if (StopConstant == 255)
			{
				MotionFalse = true;
			}

			if (MotionFalse)
			{
				triggers->Constant(constants->DIRECTION_FROM_LEFT, 0);
				triggers->Constant(constants->DIRECTION_FROM_RIGHT, 0);
				Motion = false;
				StopConstant = 0;
				MotionFalse = false;
			}

			if (!Motion)
			{

				if (stateFFB2 == 0x01)
				{
					Effect1 = true;
				}
				else
				{
					Effect1 = false;
				}

				if (Effect1)
				{
					triggers->Sine(SinePeriod, SineFadePeriod, SineStrength / 100.0);
					triggers->Rumble(RumbleStrengthLeftMotor / 100.0, RumbleStrengthRightMotor / 100.0, 100);
				}

				if (!Effect1)
				{
					triggers->Sine(0, 0, 0);
					triggers->Rumble(0, 0, 0);
				}
			}
		}

		if (RunningFFB == PDriftActive)
		{
			if (name == bank_motor_position)
			{
				helpers->log("got value: ");
				std::string ffs = std::to_string(newstateFFB);
				helpers->log((char*)ffs.c_str());

				stateFFB = newstateFFB;
			}

			if (name == vibration_motor)
			{
				stateFFB2 = newstateFFB;
			}

			if (name == upright_wheel_motor)
			{
				helpers->log("got value: ");
				std::string ffs = std::to_string(newstateFFB);
				helpers->log((char*)ffs.c_str());

				if (newstateFFB == 0)
				{
					Effect1 = false;
				}

				stateFFB3 = newstateFFB;
			}

			if (Motion)
			{
				if ((stateFFB > 0x00) && (stateFFB < 0x04))
				{
					double percentForce = (4 - stateFFB) / 3.0;
					triggers->Constant(constants->DIRECTION_FROM_LEFT, percentForce);
				}
				else if ((stateFFB > 0x04) && (stateFFB < 0x08))
				{
					double percentForce = (stateFFB - 4) / 3.0;
					triggers->Constant(constants->DIRECTION_FROM_RIGHT, percentForce);
				}

				if (stateFFB2 >= 0)
				{
					double percentForce = stateFFB2 / 7.0;
					triggers->Sine(60, 0, percentForce / 3.0);
				}
			}

			if (stateFFB == 4)
			{
				Motion = true;
				MotionFalse = false;
			}

			if (stateFFB3 == 1)
			{
				Motion = false;
			}

			if (StopConstant == 255)
			{
				MotionFalse = true;
			}

			if (MotionFalse)
			{
				triggers->Constant(constants->DIRECTION_FROM_LEFT, 0);
				triggers->Constant(constants->DIRECTION_FROM_RIGHT, 0);
				Motion = false;
				StopConstant = 0;
				MotionFalse = false;
			}

			if (!Motion)
			{
				if (stateFFB3 == 0x01)
				{
					Effect1 = true;
				}
				else
				{
					Effect1 = false;
				}

				if (Effect1)
				{
					triggers->Sine(SinePeriod, SineFadePeriod, SineStrength / 100.0);
					triggers->Rumble(RumbleStrengthLeftMotor / 100.0, RumbleStrengthRightMotor / 100.0, 100);
				}

				if (!Effect1)
				{
					triggers->Sine(0, 0, 0);
					triggers->Rumble(0, 0, 0);
				}
			}
		}

		if (RunningFFB == SuperChaseActive)
		{
			if (!PatternFind)
			{
				if (!PatternLaunch)
				{
					Sleep(8000);
					PatternLaunch = true;
				}

				if (!Scan)
				{
					CreateThread(NULL, 0, ScanThread, NULL, 0, NULL);
					Scan = true;
				}

				UINT8 CheckAddy2 = helpers->ReadByte((INT_PTR)aAddy2 + 0x12, false);
				if (CheckAddy2 == 0x5A)
				{
					FFBAddress = (INT_PTR)aAddy2 + 0x6C8;
					PatternFind = true;
				}
			}
			else
			{
				ff = helpers->ReadByte(FFBAddress, false);

				helpers->log("got value: ");
				std::string ffs = std::to_string(ff);
				helpers->log((char*)ffs.c_str());

				if (ff & 0x01)
				{
					double percentForce = 1.0;
					double percentLength = 100;
					triggers->Rumble(percentForce, 0, percentLength);
					triggers->Constant(constants->DIRECTION_FROM_LEFT, percentForce);
				}

				if (ff & 0x02)
				{
					double percentForce = 1.0;
					double percentLength = 100;
					triggers->Rumble(0, percentForce, percentLength);
					triggers->Constant(constants->DIRECTION_FROM_RIGHT, percentForce);
				}
			}
		}
		
		if (RunningFFB == NamcoFFBActive)
		{
			if (!PatternFind)
			{
				if (!PatternLaunch)
				{
					if (name == cpuled6)
					{
						if (newstateFFB == 1)
						{
							Sleep(2000);
							PatternLaunch = true;
						}
					}
				}
				else
				{
					if (romname == dirtdash || romname == dirtdasha || romname == dirtdashj)
					{
						if (!Scan)
						{
							CreateThread(NULL, 0, ScanThread, NULL, 0, NULL);
							Scan = true;
						}

						UINT8 CheckAddy2 = helpers->ReadByte((INT_PTR)aAddy2 - 0x3E3, false);
						if (CheckAddy2 == 0x80)
						{
							FFBAddress = (INT_PTR)aAddy2 - 0x2C6;
							PatternFind = true;
						}
					}
				}
			}
			else
			{
				DWORD FFBNamco = helpers->ReadInt32(FFBAddress, false);

				helpers->log("got value: ");
				std::string ffs = std::to_string(FFBNamco);
				helpers->log((char*)ffs.c_str());

				auto sendConstant = [&](int direction, double strength)
					{
						if (UseConstantInf)
							triggers->ConstantInf(direction, strength);
						else
							triggers->Constant(direction, strength);
					};

				if ((FFBNamco >= 0x00) && (FFBNamco < 0x77A))
				{
					double percentForce = (FFBNamco / Divide);
					double percentLength = 100;

					if (percentForce > 1.0)
						percentForce = 1.0;

					triggers->Rumble(0, percentForce, percentLength);
					sendConstant(constants->DIRECTION_FROM_RIGHT, percentForce);
				}
				else if ((FFBNamco > 0xF886) && (FFBNamco < 0x10000))
				{
					double percentForce = ((65536 - FFBNamco) / Divide);
					double percentLength = 100;

					if (percentForce > 1.0)
						percentForce = 1.0;

					triggers->Rumble(percentForce, 0, percentLength);
					sendConstant(constants->DIRECTION_FROM_LEFT, percentForce);
				}
			}
		}

	}
}