/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2010, 2015
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 ******************************************************************************/

/*
 * file    : primeNumberHelper.c
 *
 */

/*
 * PrimeBitsArray is used as a compact way of storing prime numbers.
 * Each bit index represents a number. If the represented number is prime, then bit is set to 1, it is set to 0 otherwise.
 *
 * Represented numbers with each index are the ones which can not be divided by 2 or 3.
 * For instance, there are 32 numbers between 0 - 90 which can not be divided by 2 or 3.
 * Therefore 32 bits (4bytes) is enough to store all the prime numbers between 0 -90.
 *
 * So primeBitsArray is used as an array of bits.
 *
 *
 * Numbers represented by this table are the list of numbers which can not be divided by 2 or 3.
 * In other words, list of numbers represented by (6*a + 1) or (6*a + 5)     (a starts from 0)
 *
 * This can be explained best with an example:
 *
 * Lets take numbers between 0 to 40. Delete the numbers that are multiples of 2 and 3.
 *
 * index			0 - 1 - 2 - 3 - 4  -  5  - 6 - 7  -  8 -  9 - 10 - 11 - 12 - 13
 *
 *					0 - 1 - 5 - 7 - 11 - 13 - 17 - 19 - 23 - 25 - 29 - 31 - 35 - 37    (These are the numbers which are not multiples of 2 or 3)
 *
 * primeBitsArray	0 - 0 - 1 - 1 - 1  -  1  - 1 - 1  - 1  -  0 - 1  - 1  - 0  - 1
 *
 * Integer value of very 32 bits set is the entry of the primeBitsArray.
 *
 * Represented number by an index can be found with this formula :
 *
 * representedNumber = (index * 3) - 1 - (index%2)
 *
 * For a given number, we can find the index of a smaller or equal number represented by the table with this formula :
 *
 * index =  number - (number/2) - (number/3) + (number/6)
 *
 * By using index, represented number can be found by applying the formula mentioned above.
 *
 * Currently there are 300 numbers in the table.
 * Max index = 300*32 - 1 = 9599
 * Max or last number represented = 9599*3 - 1 - 1 = 28795
 *
 * To generate this table, there is an implemented java program that can be used.
 *
 *
 * 			SEE JAZZ 36969: Implement a java program that generates primeBitsArray entries
 *
 */

#include "omrutil.h"

#undef PRIMEBITSARRAYGENERATOR
static const uint32_t primeBitsArray[] = {
    4290227674UL,
    2115712428UL,
    4045327031UL,
    568413845UL,
    2790054520UL,
    2577597739UL,
    1255609260UL,
    1764005270UL,
    1629699207UL,
    2273415786UL,
    445934803UL,
    874423616UL,
    3374991028UL,
    1211857104UL,
    44306974UL,
    2635327625UL,
    379160301UL,
    542902051UL,
    626023496UL,
    2424697386UL,
    204482937UL,
    1283761096UL,
    3279044865UL,
    2755202646UL,
    808296822UL,
    2324072800UL,
    273265672UL,
    3261207445UL,
    3922929170UL,
    923298144UL,
    2460256363UL,
    13207109UL,
    436519425UL,
    3314181135UL,
    269310744UL,
    3425738818UL,
    2080969965UL,
    825366165UL,
    148989077UL,
    46688306UL,
    478560699UL,
    403710893UL,
    54693136UL,
    3899670603UL,
    858573376UL,
    321200290UL,
    811238177UL,
    2014072981UL,
    70996616UL,
    2204143646UL,
    3322938530UL,
    344888545UL,
    1529907462UL,
    2370832921UL,
    608296994UL,
    3265339776UL,
    714544960UL,
    3090733061UL,
    1686114527UL,
    560242804UL,
    26387739UL,
    1824686472UL,
    1076369445UL,
    2706580044UL,
    2434808164UL,
    313822378UL,
    1389700101UL,
    50743298UL,
    1103847569UL,
    70013748UL,
    2248346824UL,
    507687177UL,
    2685196950UL,
    689456256UL,
    2730528842UL,
    489005064UL,
    1280061504UL,
    1094847238UL,
    3375000774UL,
    2978224646UL,
    1501922416UL,
    100835873UL,
    2015925809UL,
    4407429UL,
    585410568UL,
    1494240488UL,
    371070016UL,
    1246495153UL,
    2231378515UL,
    2166632988UL,
    1353083217UL,
    1782677900UL,
    2990019585UL,
    1686831324UL,
    591986964UL,
    370550042UL,
    683804448UL,
    2557741589UL,
    753941130UL,
    304709640UL,
    1169245234UL,
    1086693573UL,
    2303101713UL,
    2232099860UL,
    12595244UL,
    2375036058UL,
    1644724649UL,
    3258076804UL,
    1083182599UL,
    2223784704UL,
    2418450833UL,
    1477980520UL,
    1092911124UL,
    2903184387UL,
    606685192UL,
    322019441UL,
    80610336UL,
    425890070UL,
    1086460552UL,
    2239859536UL,
    2419067232UL,
    1644299852UL,
    823133090UL,
    2781878290UL,
    2712425256UL,
    403128512UL,
    1853925120UL,
    688442534UL,
    1141512199UL,
    308568386UL,
    2593426754UL,
    1414334120UL,
    2186428805UL,
    76690500UL,
    6928418UL,
    2508439658UL,
    268804737UL,
    2572682018UL,
    1224820251UL,
    8663392UL,
    1252296776UL,
    1108481065UL,
    1107615283UL,
    1085809808UL,
    839415866UL,
    1275166771UL,
    101323649UL,
    1476100UL,
    2215313476UL,
    2206532108UL,
    1502921746UL,
    277264128UL,
    3224274465UL,
    141126297UL,
    2217052428UL,
    2583775650UL,
    268832804UL,
    1764248354UL,
    558910017UL,
    3033092868UL,
    3331465497UL,
    705040516UL,
    2452640035UL,
    3315073055UL,
    581020240UL,
    17220952UL,
    1082921600UL,
    1082006160UL,
    2348817922UL,
    2959163424UL,
    2233680897UL,
    1780221600UL,
    302666753UL,
    2294505997UL,
    2152011784UL,
    145817754UL,
    811237645UL,
    1093555204UL,
    690503824UL,
    2982187072UL,
    218539152UL,
    1581453633UL,
    2873393424UL,
    1815222275UL,
    587285068UL,
    1085309233UL,
    273199944UL,
    829162499UL,
    3424796892UL,
    2688848214UL,
    237028802UL,
    572065313UL,
    1499481223UL,
    205527554UL,
    67408162UL,
    2292457832UL,
    8462344UL,
    4027090178UL,
    1621165776UL,
    34351152UL,
    487868738UL,
    612630573UL,
    2289980085UL,
    1157706378UL,
    2235564064UL,
    1394903256UL,
    1111819045UL,
    50500131UL,
    685847576UL,
    2420468252UL,
    1182927042UL,
    605159845UL,
    1913034771UL,
    3673156UL,
    2969587976UL,
    3229753649UL,
    512499904UL,
    37917570UL,
    1226321999UL,
    2416771624UL,
    1101351361UL,
    672146688UL,
    2015888278UL,
    2285897821UL,
    2269133388UL,
    3456156744UL,
    571675809UL,
    408996242UL,
    545411138UL,
    354529562UL,
    2352046449UL,
    100671624UL,
    4179099808UL,
    3298951764UL,
    587497780UL,
    469773369UL,
    76228236UL,
    2186811904UL,
    748693570UL,
    2199931244UL,
    3348269089UL,
    278144833UL,
    17075730UL,
    2820866178UL,
    277364804UL,
    187139162UL,
    503362752UL,
    272258082UL,
    700466837UL,
    876618082UL,
    1369523369UL,
    1581649996UL,
    672438274UL,
    2244749UL,
    279713798UL,
    1092919681UL,
    34115592UL,
    2839807009UL,
    2219974745UL,
    71383058UL,
    455090400UL,
    1108481665UL,
    1259602213UL,
    2751478849UL,
    2761982736UL,
    2528116744UL,
    1615045444UL,
    1481278596UL,
    622396097UL,
    46219794UL,
    2375042104UL,
    1682178313UL,
    3491908257UL,
    1092827142UL,
    638132490UL,
    2459191314UL,
    1644234272UL,
    2685030435UL,
    2901098626UL,
    2183418416UL,
    3431104976UL,
    705302797UL,
    1629229184UL,
    144769221UL,
    386400832UL,
    1342488994UL,
    1087381708UL,
    2150631952UL,
    2688770055UL,
    2980633176UL,
    402727984UL,
    978355721UL,
    2168738609UL,
    8925257UL,
    536885836UL,
    2150629707UL,
    110134312UL,
    1617726741UL,
    2374661138UL,
    2436944134UL,
    369428880UL,
    609493512UL,
    41550212UL,
    67848725UL,
    314870020UL,
    311470344UL,
    482911520UL,
    1210063360UL,
    3843098176UL,
    2969577506UL,
    3223390305UL,
    448792193UL,
    269749280UL,
    2290308743UL,
    38086928UL,
    1160782168UL,
    672149761UL,
    2181828132UL,
    1215316480UL,
    356819546UL,
    268772362UL,
    1154298400UL,
    2170817152UL,
    676402376UL,
    50974838UL,
    26536352UL,
    148243465UL,
    3758096422UL,
    1088501780UL,
    2189494872UL,
    285459587UL,
    42074312UL,
    1225261061UL,
    613026827UL,
    2772971568UL,
    2226200673UL,
    1610851204UL,
    1533037731UL,
    17913870UL,
    57215778UL,
    335585648UL,
    67741440UL,
    3624144948UL,
    740498052UL,
    2757806346UL,
    2150763673UL,
    269484228UL,
    2736685585UL,
    1627415700UL,
    2187397740UL,
    3349577744UL,
    306263264UL,
    2735475344UL,
    1619615824UL,
    67686496UL,
    116017UL,
    269357101UL,
    1215468050UL,
    3288867970UL,
    831311956UL,
    11640963UL,
    177504841UL,
    941625603UL,
    3232252545UL,
    587464728UL,
    220416418UL,
    646447621UL,
    21547029UL,
    2286428753UL,
    2227437836UL,
    1585471720UL,
    1073746944UL,
    51021831UL,
    1085346947UL,
    287345234UL,
    2651063624UL,
    1275728385UL,
    2185513124UL,
    693121540UL,
    2684371278UL,
    2248262809UL,
    412099872UL,
    2839953698UL,
    2378310162UL,
    344742680UL,
    84225042UL,
    1611793672UL,
    287621761UL,
    543166019UL,
    122167824UL,
    1350657442UL,
    1281175688UL,
    1246760196UL,
    16789644UL,
    279220808UL,
    1409505UL,
    9707776UL,
    1342575270UL,
    145760849UL,
    2262860098UL,
    1108992UL,
    536905408UL,
    1258589236UL,
    701123600UL,
    2432979242UL,
    143073361UL,
    1107395456UL,
    307922183UL,
    76697288UL,
    2385968UL,
    2625914905UL,
    536982020UL,
    2317357456UL,
    160437396UL,
    575180844UL,
    3534062594UL,
    1107927136UL,
    2953843985UL,
    3234481668UL,
    371206656UL,
    9830656UL,
    503386537UL,
    319849108UL,
    1093664775UL,
    537434376UL,
    1168302360UL,
    1343562272UL,
    1095801350UL,
    6370371UL,
    2737162324UL,
    1090528416UL,
    747372833UL,
    285917600UL,
    141256793UL,
    578818624UL,
    3389153291UL,
    278302853UL,
    1915783041UL,
    80355337UL,
    72180280UL,
    2181245193UL,
    1149572544UL,
    1769609504UL,
    539182088UL,
    54602356UL,
    2458952032UL,
    616923148UL,
    173166881UL,
    673388548UL,
    2216726596UL,
    1350829193UL,
    46661632UL,
    3104328194UL,
    2283810823UL,
    350307108UL,
    135659600UL,
    2118123553UL,
    50463891UL,
    1637903429UL,
    281320192UL,
    2300806146UL,
    1589903360UL,
    2704540160UL,
    1611229326UL,
    2701721714UL,
    1510050946UL,
    571352136UL,
    419992612UL,
    2287540244UL,
    2369536UL,
    3674344608UL,
    34701921UL,
    846217761UL,
    558891082UL,
    2166645260UL,
    2215774561UL,
    1208096136UL,
    8012960UL,
    2684360329UL,
    537199394UL,
    226501953UL,
    947987460UL,
    3492549168UL,
    68223194UL,
    340363268UL,
    2486306906UL,
    282624385UL,
    2734693168UL,
    622993540UL,
    67133504UL,
    1258332314UL,
    1547706500UL,
    553948836UL,
    147336211UL,
    302514538UL,
    1417757842UL,
    344392204UL,
    3765437204UL,
    3358082112UL,
    2485750368UL,
    44056657UL,
    80217353UL,
    1612747026UL,
    146825736UL,
    2229281298UL,
    3657542665UL,
    101286084UL,
    1879051286UL,
    2366795795UL,
    826343434UL,
    70338792UL,
    1145087752UL,
    591583360UL,
    607143949UL,
    29410118UL,
    159778827UL,
    1283458337UL,
    1344029200UL,
    2367691864UL,
    2434834688UL,
    3548643536UL,
    840705188UL,
    2601157120UL,
    2239771160UL,
    308549720UL,
    176294912UL,
    1376890885UL,
    3490191377UL,
    17310230UL,
    537154122UL,
    203505827UL,
    104862092UL,
    2147749396UL,
    1081623746UL,
    2172715580UL,
    1082174898UL,
    584095240UL,
    2288161812UL,
    2287534784UL,
    549529676UL,
    2234526018UL,
    604901445UL,
    21774466UL,
    2169009216UL,
    2221474594UL,
    1073957248UL,
    33947716UL,
    2721208704UL,
    1099958794UL,
    849420816UL,
    369363994UL,
    813831588UL,
    406853668UL,
    3831630924UL,
    637587468UL,
    3240198224UL,
    1616447008UL,
    270012464UL,
    1088640646UL,
    36188416UL,
    2257594498UL,
    1616577928UL,
    2416593924UL,
    1208557637UL,
    293879872UL,
    136618137UL,
    140116844UL,
    704907142UL,
    219705410UL,
    2961264646UL,
    1343269136UL,
    101197313UL,
    807699842UL,
    1141072512UL,
    2759919872UL,
    1461798913UL,
    34574372UL,
    285262368UL,
    2223122433UL,
    558682170UL,
    1242963976UL,
    177710400UL,
    2188401696UL,
    2167013572UL,
    44845316UL,
    419741746UL,
    469831712UL,
    307380757UL,
    561132700UL,
    2151723270UL,
    26379457UL,
    1209368805UL,
    138546739UL,
    1151866496UL,
    109601352UL,
    2309040328UL,
    810103172UL,
    51123364UL,
    553666580UL,
    2160079114UL,
    1074159890UL,
    1184501797UL,
    3389297922UL,
    203954182UL,
    270633578UL,
    19939779UL,
    110769408UL,
    2147893761UL,
    3368634572UL,
    100696148UL,
    352526464UL,
    1620381860UL,
    688652304UL,
    159298UL,
    2173215540UL,
    212148568UL,
    613450956UL,
    1477591040UL,
    615664275UL,
    60932166UL,
    17204225UL,
    1812574249UL,
    169478420UL,
    1077940368UL,
    37789984UL,
    2250637355UL,
    940909248UL,
    38800144UL,
    1612796420UL,
    2216757824UL,
    102926336UL,
    73045196UL,
    303076871UL,
    675356673UL,
    550271058UL,
    1073906057UL,
    1074332228UL,
    3254782096UL,
    604585997UL,
    2232158784UL,
    1085383056UL,
    448823649UL,
    2840219781UL,
    1084235781UL,
    84185092UL,
    337808777UL,
    1083576840UL,
    326109234UL,
    2822767107UL,
    2441183248UL,
    1115687272UL,
    1745166596UL,
    2823456001UL,
    2215187012UL,
    302580006UL,
    42125315UL,
    1006645257UL,
    1347557408UL,
    137429072UL,
    101245258UL,
    1379159064UL,
    437584548UL,
    273472032UL,
    3380827282UL,
    2183420432UL,
    3330278722UL,
    67241128UL,
    1612204065UL,
    14748674UL,
    2483066928UL,
    2483037208UL,
    42729800UL,
    1073877778UL,
    1698707588UL,
    604047410UL,
    167796913UL,
    550637632UL,
    688784528UL,
    1285171229UL,
    2166362188UL,
    337739873UL,
    571835584UL,
    272679829UL,
    219301402UL,
    76378880UL,
    1109410233UL,
    138478272UL,
    2821849126UL,
    2173312002UL,
    40402976UL,
    2148541440UL,
    1489404192UL,
    2186807585UL,
    1682115138UL,
    555747426UL,
    1160839330UL,
    541885760UL,
    421299713UL,
    71983744UL,
    2186043948UL,
    252740802UL,
    134324288UL,
    2469270534UL,
    1753827475UL,
    579371264UL,
    2166432952UL,
    1414603041UL,
    153099654UL,
    2302677061UL,
    277397544UL,
    1208019216UL,
    549457984UL,
    2164555781UL,
    3228248137UL,
    2156142850UL,
    2166458562UL,
    1410994220UL,
    1100708UL,
    2164785737UL,
    805650436UL,
    2427519208UL,
    580091904UL,
    1616906659UL,
    26237519UL,
    532482UL,
    8397857UL,
    1141048200UL,
    36573956UL,
    142811264UL,
    390598952UL,
    2165771304UL,
    1892722240UL,
    2185646096UL,
    742397067UL,
    46465604UL,
    211848464UL,
    1477452864UL,
    1108476035UL,
    1630610114UL,
    877441296UL,
    2166505490UL,
    441978944UL,
    1651512324UL,
    3981970573UL,
    622909456UL,
    305217632UL,
    34639913UL,
    3491775008UL,
    3291097297UL,
    606406938UL,
    2165416035UL,
    872481504UL,
    20712500UL,
    2168480273UL,
    2147778604UL,
    1182802320UL,
    1074168260UL,
    3525874945UL,
    2149601281UL,
    828737862UL,
    2248435768UL,
    814219940UL,
    2359301UL,
    136385560UL,
    323551330UL,
    85262378UL,
    172532960UL,
    688047394UL,
    2158039041UL,
    2160666696UL,
    26353680UL,
    1746408492UL,
    18141735UL,
    1216364694UL,
    352348272UL,
    218259586UL,
    207098529UL,
    588252160UL,
    2306017481UL,
    67471462UL,
    444687376UL,
    927232UL,
    402916386UL,
    3292747908UL,
    608242250UL,
    305365152UL,
    8426156UL,
    1632635682UL,
    672799816UL,
    2158321698UL,
    69271617UL,
    1611773696UL,
    2415970689UL,
    1094189076UL,
    292293136UL,
    75548936UL,
    809538209UL,
    2423275781UL,
    2156071554UL,
    69230944UL,
    1093959880UL,
    176202496UL,
    2287226914UL,
    604004888UL,
    304101948UL,
    2282031506UL,
    1342378112UL,
    3003535541UL,
    1635868753UL,
    46717208UL,
    1149640722UL,
    402980960UL,
    2186318354UL,
    1209016387UL,
    94947334UL,
    1090848160UL,
    672137729UL,
    805868084UL,
    205738512UL,
    2170552650UL,
    1107299754UL,
    277218532UL,
    304087840UL,
    9965584UL,
    2418659370UL,
    1077020760UL,
    612770952UL,
    1897531394UL,
    536954049UL,
    577093700UL,
    520093730UL,
    1078895493UL,
    1110966656UL,
    2838503560UL,
    335642670UL,
    370197713UL,
    311436357UL,
    168300576UL,
    3234005522UL,
    75503916UL,
    171410496UL,
    1279500616UL,
    3255829045UL,
    1615332423UL,
    2478876768UL,
    2282038328UL,
    310379305UL,
    18254850UL,
    1141919744UL,
    614586880UL,
    153403810UL,
    940712544UL,
    272667681UL,
    202592796UL,
    31764746UL,
    19529UL,
    370382341UL,
    271057202UL,
    557850626UL,
    2980643588UL,
    3625084993UL,
    1073808320UL,
    942312452UL,
    2148209153UL,
    17050128UL,
    294937632UL,
    1073873293UL,
    3360555280UL,
    203429074UL,
    2504564800UL,
    34015394UL,
    1623490628UL,
    809518608UL,
    541607432UL,
    2452095512UL,
    167816450UL,
    5931276UL,
    2436141184UL,
    158338050UL,
    847555160UL,
    1101209744UL,
    67121256UL,
    1096976914UL,
    21170179UL,
    805326856UL,
    1393575202UL,
    542941729UL,
    268616869UL,
    2281722380UL,
    54788364UL,
    2619375721UL,
    67765901UL,
    405538964UL,
    545268227UL,
    899678740UL,
    201326737UL,
    1275077888UL,
    3780135302UL,
    1075467294UL,
    285532964UL,
    2223121697UL,
    604832297UL,
    269221892UL,
    1620185624UL,
    2149591396UL,
    116882UL,
    571213376UL,
    2283324464UL,
    218181646UL,
    103311424UL,
    2155971912UL,
    38286605UL,
    1880884403UL,
    1083793601UL,
    2424334594UL,
    69632161UL,
    281416584UL,
    537166852UL,
    1073889288UL,
    2248933920UL,
    1392511009UL,
    402698280UL,
    1208483888UL,
    3221846080UL,
    38076678UL,
    3741394248UL,
    1350701120UL,
    1784695345UL,
    2237153792UL,
    560046118UL,
    75776009UL,
    713429320UL,
    555930627UL,
    2159610375UL,
    843055106UL,
    2441366610UL,
    134948104UL,
    408181648UL,
    700581968UL,
    555857992UL,
    2425503808UL,
    42796928UL,
    805716241UL,
    3774877827UL,
    310915156UL,
    136315208UL,
    844136581UL,
    2701658660UL,
    1212154051UL,
    46979090UL,
    2149933065UL,
    1409810661UL,
    1628571520UL,
    675422222UL,
    2416218114UL,
    143663201UL,
    542934529UL,
    1074020758UL,
    3223978568UL,
    83988498UL,
    119606633UL,
    67245089UL,
    1786299664UL,
    219289600UL,
    348405784UL,
    3526568232UL,
    1112617540UL,
    2188903682UL,
    2226129472UL,
    11020882UL,
    219171088UL,
    80642945UL,
    440404608UL,
    2298482910UL,
    2168485920UL,
    1344536584UL,
    813761281UL,
    50858000UL,
    3838338073UL,
    2227192400UL,
    2167800002UL,
    5316644UL,
    1091328176UL,
    137374416UL,
    2231386936UL,
    3297059843UL,
    1319297UL,
    23464326UL,
    3225556996UL,
    838883880UL,
    9561473UL,
    302133544UL,
    3496644628UL,
    2281837125UL,
    587569160UL,
    421676072UL,
    1711800325UL,
    1766327475UL,
    671106632UL,
    356593932UL,
    1174480912UL,
    1073882252UL,
    288489890UL,
    1611350530UL,
    34113892UL,
    2516877408UL,
    742392069UL,
    2152729381UL,
    1227896858UL,
    2195714UL,
    2233959440UL,
    37782656UL,
    3007841298UL,
    134754320UL,
    15540244UL,
    1166019720UL,
    239829216UL,
    50466832UL,
    1073826820UL,
    600610816UL,
    2558697731UL,
    1079116292UL,
    168820992UL,
    2768323587UL,
    125895244UL,
    421603665UL,
    142902048UL,
    539541664UL,
    1088634885UL,
    46146062UL,
    389073224UL,
    579240480UL,
    437554976UL,
    612373067UL,
    71311372UL,
    437665936UL,
    68288960UL,
    2573211777UL,
    85069508UL,
    42025558UL,
    2165703946UL,
    4731144UL,
    172228768UL,
    1086461460UL,
    67211586UL,
    75958473UL,
    1074864420UL,
    3092021264UL,
    1677854213UL,
    2149909000UL,
    3365969920UL,
    169509893UL,
    304613506UL,
    1106257092UL,
    2244214794UL,
    3556844824UL,
    1351163969UL,
    707927554UL,
    605620292UL,
    2183403628UL,
    136609904UL,
    378013256UL,
    675857809UL,
    212875329UL,
    570734662UL,
    1291856930UL,
    1083180224UL,
    1629504385UL,
    697829912UL,
    27357216UL,
    213089UL,
    71374336UL,
    3271692418UL,
    2148142237UL,
    17039696UL,
    34865155UL,
    142877697UL,
    3526363665UL,
    8521302UL,
    2418542916UL,
    1367408642UL,
    139200257UL,
    34766865UL,
    3437896213UL,
    12670988UL,
    1166049496UL,
    5386625UL,
    36864512UL,
    147915282UL,
    2986893328UL,
    2298946986UL,
    281355009UL,
    2198112276UL,
    558958721UL,
    2483060808UL,
    41984017UL,
    210543616UL,
    425776422UL,
    2149713929UL,
    2766415872UL,
    1426088265UL,
    538186432UL,
    4456593UL,
    155324954UL,
    2217263104UL,
    279134216UL,
    739705092UL,
    1901643813UL,
    2694924876UL,
    8651120UL,
    1051938UL,
    1950712457UL,
    3493347456UL,
    765466690UL,
    654852130UL,
    104090648UL,
    1074300481UL,
    151420961UL,
    161497088UL,
    39927820UL,
    66586UL,
    542118056UL,
    1881687568UL,
    20466242UL,
    2172944672UL,
    2626028562UL,
    202965513UL,
    3377598608UL,
    3825211523UL,
    35917936UL,
    59008097UL,
    134223168UL,
    537661714UL,
    1087907840UL,
    2812357148UL,
    3625066530UL,
    302158381UL,
    318818336UL,
    554717768UL,
    92905490UL,
    1278345520UL,
    1745986636UL,
    271712262UL,
    75499025UL,
    868763986UL,
    2189558016UL,
    1351196928UL,
    302006400UL,
    73475656UL,
    319295488UL,
    18221105UL,
    806651365UL,
    705976322UL,
    8586762UL,
    11272720UL,
    3240601986UL,
    1140863328UL,
    18141344UL,
    25250820UL,
    2953062504UL,
    67125656UL,
    136192552UL,
    6457478UL,
    687882316UL,
    279744558UL,
    313532496UL,
    109446152UL,
    2150371986UL,
    1212686484UL,
    2263094096UL,
    455278632UL,
    67174917UL,
    1085091UL,
    67653656UL,
    274696UL,
    2417035296UL,
    651235464UL,
    561563779UL,
    1621696222UL,
    543244288UL,
    2415969337UL,
    805438497UL,
    39977732UL,
    2155884562UL,
    16791812UL,
    3280226344UL,
    631329UL,
    705971219UL,
    23724544UL,
    2256566372UL,
    19269778UL,
    269090952UL,
    17470464UL,
    21054150UL,
    55350018UL,
    10904626UL,
    168886596UL,
    1075844102UL,
    738224257UL,
    94423056UL,
    1216628752UL,
    886735616UL,
    270795056UL,
    138938952UL,
    656449616UL,
    2214634667UL,
    1914213484UL,
    2033191937UL,
    218237008UL,
    5062944UL,
    2452750360UL,
    1183055940UL,
    2435319941UL,
    2223573007UL,
    537411584UL,
    2189607185UL,
    671102217UL,
    1107837073UL,
    3763480066UL,
    2267054116UL,
    2483126474UL,
    281616897UL,
    318917664UL,
    564658179UL,
    2488011072UL,
    50399440UL,
    878187817UL,
    587384839UL,
    1218461831UL,
    805333344UL,
    1140883723UL,
    67961064UL,
    1614807170UL,
    1628640262UL,
    2418016788UL,
    144772160UL,
    643310601UL,
    2684928273UL,
    71399960UL,
    10485770UL,
    2451688707UL,
    8753153UL,
    1745358610UL,
    1573891UL,
    545260050UL,
    70598785UL,
    1241978060UL,
    138972292UL,
    1637024840UL,
    54544690UL,
    167952689UL,
    1346372996UL,
    1376915461UL,
    672203784UL,
    2518777858UL,
    9439402UL,
    1209107076UL,
    2735096609UL,
    2281788952UL,
    2487825016UL,
    33991696UL,
    943718664UL,
    2737045536UL,
    159974996UL,
    3033008160UL,
    3558909193UL,
    176885956UL,
    3760198162UL,
    2148011008UL,
    18942468UL,
    1244758113UL,
    785129992UL,
    554439683UL,
    3363904129UL,
    58787854UL,
    3221315746UL,
    1947469320UL,
    855641216UL,
    605041218UL,
    537481772UL,
    402802793UL,
    5378120UL,
    688017536UL,
    1082803329UL,
    541165600UL,
    117868882UL,
    1083016321UL,
    3224518932UL,
    622864542UL,
    67209318UL,
    75530377UL,
    570795524UL,
    528899UL,
    692138628UL,
    281026932UL,
    61964288UL,
    236000352UL,
    1110462978UL,
    4720261UL,
    2248692594UL,
    2172690432UL,
    1283461133UL,
    2286158976UL,
    628171776UL,
    2257356836UL,
    294668353UL,
    412131872UL,
    2152468752UL,
    10512585UL,
    564240722UL,
    36774912UL,
    269681380UL,
    402673046UL,
    2165327896UL,
    2418020638UL,
    1108345256UL,
    1686111236UL,
    1214405892UL,
    92278860UL,
    304089362UL,
    2241201152UL,
    411762688UL,
    1209290784UL,
    14745792UL,
    2166892548UL,
    318948515UL,
    1615364384UL,
    403706882UL,
    2701272065UL,
    2529176148UL,
    3367282952UL,
    538117449UL,
    1610762256UL,
    673194516UL,
    577546UL,
    2216895536UL,
    1108873869UL,
    2152107028UL,
    1164575936UL,
    822122532UL,
    61153312UL,
    206569512UL,
    3764551809UL,
    210975304UL,
    2219051586UL,
    3489677666UL,
    872449760UL,
    1076379907UL,
    135947275UL,
    619200558UL,
    271777920UL,
    143009088UL,
    1207976960UL,
    2754626200UL,
    17107270UL,
    2432860417UL,
    281575981UL,
    270008993UL,
    3356692626UL,
    624978186UL,
    18877659UL,
    1079312448UL,
    35133987UL,
    138412048UL,
    73728784UL,
    1099957442UL,
    336068900UL,
    2198341270UL,
    2695172UL,
    381694568UL
};

#define SIZE_IN_BITS(obj) (sizeof(obj) * 8)
#define IS_BIT_SET(number, index) (number & (((uintptr_t)1) << (SIZE_IN_BITS(uint32_t) - index - 1)))
#define GET_PRIMEBITSARRAY_BITINDEX(number) (number - (number / 2) - (number / 3) + (number / 6))
#define GET_NUMBER_FROM_PRIMEBITSARRAY_BITINDEX(index) ((index * 3) - 1 - (index % 2))
#define PRIMEBITSARRAY_ENTRYSIZE sizeof(primeBitsArray) / sizeof(uint32_t)
#define SUPPORTED_LAST_INDEX ((PRIMEBITSARRAY_ENTRYSIZE * SIZE_IN_BITS(uint32_t)) - 1)
#define SUPPORTED_UP_TO GET_NUMBER_FROM_PRIMEBITSARRAY_BITINDEX(SUPPORTED_LAST_INDEX)

/**
 *	This function returns the biggest number supported by primeNumberHelper.
 *	This number is represented by the last bit index of primeBitsArray
 *
 *	@return A number represented by the last bit index of primeBitsArray
 */
uintptr_t getSupportedBiggestNumberByPrimeNumberHelper()
{
    return SUPPORTED_UP_TO;
}

/**
 * For a given index for the primeBitsArray,
 * it checks whether the bit at index is set or not.
 */
static BOOLEAN
isPrimeBitSet(uintptr_t primeBitsArrayBitIndex)
{
    uintptr_t primeBitsArrayEntryIndex = primeBitsArrayBitIndex / SIZE_IN_BITS(uint32_t);
    uintptr_t localBitIndex = primeBitsArrayBitIndex % SIZE_IN_BITS(uint32_t);
    uintptr_t primeBitsEntry = primeBitsArray[primeBitsArrayEntryIndex];

    return IS_BIT_SET(primeBitsEntry, localBitIndex);
}

/**
 *
 * For the given number, it finds the biggest prime number which smaller than or equal to the given number.
 * If the given number is prime itself, then it is returned.
 * Otherwise, closest smaller prime number is found and returned.
 * It uses primeBitsArray if the given number is in the supported range of the table.
 *
 * @param 	number	A number which this function finds the largest prime less than or equal to
 * @return 	0 If smaller prime can not be found. It is the case if user passes 0 or 1.
 * 			PRIMENUMBERHELPER_OUTOFRANGE If the given number is not in the supported range of primeBitsArray.
 * 			Otherwise, the largest prime number smaller than or equal to the given number.
 */

uintptr_t findLargestPrimeLessThanOrEqualTo(uintptr_t number)
{
    uintptr_t index;

    if (number < 2) {
        return 0;
    } else if (number == 2) {
        return 2;
    } else if (number < 5) {
        return 3;
    }

    if (number <= SUPPORTED_UP_TO) {
        index = GET_PRIMEBITSARRAY_BITINDEX(number);
        for (; index > 0; index--) {
            if (isPrimeBitSet(index)) {
                return GET_NUMBER_FROM_PRIMEBITSARRAY_BITINDEX(index);
            }
        }
    }

    return PRIMENUMBERHELPER_OUTOFRANGE; /* If the number is not in the range that is supported by primeBitsArray */
}

/**
 *
 * For the given number, it finds the smallest prime number which bigger than or equal to the given number.
 * If the given number is prime itself, then it is returned.
 * Otherwise, closest bigger prime number is found and returned.
 * It uses primeBitsArray if the given number is in the supported range of the table.
 *
 * @param 	number	A number which this function finds the smallest prime bigger than or equal to
 * @return 	0 If bigger prime can not be found in the supported range of primeBitsArray.
 * 			This is the case a given number is bigger than the biggest supported prime by primeBitsArray.
 * 			PRIMENUMBERHELPER_OUTOFRANGE If the given number is not in the supported range of primeBitsArray.
 * 			Otherwise, the smallest prime number bigger than or equal to the given number.

 */

uintptr_t findSmallestPrimeGreaterThanOrEqualTo(uintptr_t number)
{
    uintptr_t currentNumber;
    uintptr_t index;

    if (number <= 2) {
        return 2;
    } else if (number == 3) {
        return 3;
    }

    if (number <= SUPPORTED_UP_TO) {
        index = GET_PRIMEBITSARRAY_BITINDEX(number);
        for (; index <= SUPPORTED_LAST_INDEX; index++) {
            if (isPrimeBitSet(index)) {
                currentNumber = GET_NUMBER_FROM_PRIMEBITSARRAY_BITINDEX(index);
                if (currentNumber >= number) {
                    return currentNumber;
                }
            }
        }
    }
    return PRIMENUMBERHELPER_OUTOFRANGE; /* If the number is not in the range that is supported by primeBitsArray */
}

#ifdef PRIMEBITSARRAYGENERATOR

/**
 * This is the java program that generates the primeBitsArray entries.
 *
 * The output shows every number represented by primeBitsArray and tells whether they are prime or not.
 *
 * It also shows the integer value of every 32 bit sequence which is an entry for the primeBitsArray
 *
 * At the end of walking through the numbers, it prints all the values in the primeBitsArray line by line.
 *
 * At the very end, it prints the brief summary of general information.
 *
 * It also gives statistical information about max and average number of iterations
 * that is needed to find the prime numbers.
 *
 * USAGE: It requires only one arg which tells the number of entries in the primeBitsArray.
 *
 *  Copy the following code into PrimeBitsArrayGenerator.java file.
 *  Compile this file.
 *  Run it : java -cp ... ibm.PrimeBitsArrayGenerator  <number of primeBitsArray entries>
 *
 */

package ibm;

public
class PrimeBitsArrayGenerator {

    /**
	 * @param args
	 */
public
    static void main(String[] args)
    {
        int size = Integer.parseInt(args[0]);
        PrimeBitsArrayGenerator primeBitsArrayGenerator = new PrimeBitsArrayGenerator();
        primeBitsArrayGenerator.run(size);
    }

public
    static int findPrime(int number)
    {
        for (int i = number; i > 2; i--) {
            if (isPrime(i)) {
                return i;
            }
        }
        return 0;
    }

public
    static boolean isPrime(int number)
    {
        for (int i = 2; i < (number / 2) + 2; i++) {
            if ((number % i) == 0) {
                return false;
            }
        }
        return true;
    }

public
    void run(int size)
    {

        int[][] primeBitsArray = new int[size][32];
        long[] entries = new long[size];
        int bitIndex;
        int matchingNumber;

        int maxSequenceOfZero = 0;
        int currentSequenceOfZero = 0;
        int primeNumberCounter = 0;
        int maxPrime = 0;

        for (int entry_index = 0; entry_index < size; entry_index++) {
            System.out.println("\n=========================Contents of primeBitsArray[" + entry_index + "]" + "=======================");
            int localBitIndex;
            System.out.println("\n\tLocal Index\tBit Index\tCorresponding Number\tPrime?");
            for (localBitIndex = 0; localBitIndex < 32; localBitIndex++) {
                bitIndex = localBitIndex + 32 * entry_index;
                matchingNumber = getNumberFromIndex(bitIndex);
                if (localBitIndex % 4 == 0) {
                    System.out.print("\n");
                }
                System.out.print("\t    " + localBitIndex + "\t\t   " + bitIndex + "\t\t\t" + matchingNumber);
                if (isPrime(matchingNumber)) {
                    System.out.println("\t\t 1");
                    primeBitsArray[entry_index][localBitIndex] = 1;
                    if (currentSequenceOfZero > maxSequenceOfZero) {
                        maxSequenceOfZero = currentSequenceOfZero;
                    }
                    currentSequenceOfZero = 0;
                    primeNumberCounter++;
                    maxPrime = matchingNumber;
                } else {
                    System.out.println("\t\t 0");
                    primeBitsArray[entry_index][localBitIndex] = 0;
                    currentSequenceOfZero++;
                }
            }
            long currentEntry = 0;
            for (int j = 31; j >= 0; j--) {
                int bit = primeBitsArray[entry_index][j];
                double power = Math.pow(2, 31 - j);
                currentEntry += bit * power;
            }
            entries[entry_index] = currentEntry;

            System.out.print("\nBits of primeBitsArray[" + entry_index + "]:");
            for (int i = 0; i < 32; i++) {
                if (i % 4 == 0) {
                    System.out.print("\t");
                }
                System.out.print(primeBitsArray[entry_index][i]);
            }
            System.out.println("\t = \t" + currentEntry);
        }

        System.out.println("\n*****************************PrimeBitsArray entries***********************\n");
        System.out.println("static const uint32_t primeBitsArray[] =\n{");
        for (int j = 0; j < size; j++) {
            System.out.println("\t\t" + entries[j] + "UL" + (j == size - 1 ? "" : ","));
        }
        System.out.println("};");
        int maxBitIndex = size * 32 - 1;
        int supportedRange = getNumberFromIndex(maxBitIndex);
        System.out.println("\n*****************************SUMMARY***********************\n");
        System.out.println("Number of entries in primeBitsArray:\t" + size);
        System.out.println("Supported range :\t0 - " + supportedRange);
        System.out.println("Max prime number in the range:\t" + maxPrime);
        System.out.println("Number of primes in the range:\t" + primeNumberCounter);
        System.out.println("Max number of 0s in a row :\t" + maxSequenceOfZero);

        System.out.printf("Average number of iterations to find the prime: in the following ranges:\n");
        System.out.printf("\tRange\t\tAve. # of iterations\tMax # of iterations\n");
        int totalIteration = 0;
        int maxIteration = 0;
        for (int k = 0; k < supportedRange; k++) {
            int bit_index = getIndexFromNumber(k);
            int currentIteration = 0;

            for (int m = bit_index; m >= 0; m--) {
                totalIteration++;
                currentIteration++;
                int entry_index = m / 32;
                int local_bit_index = m % 32;
                if (primeBitsArray[entry_index][local_bit_index] == 1) {
                    break;
                }
                if (currentIteration > maxIteration) {
                    maxIteration = currentIteration;
                }
            }
            if ((k != 0) && (k % 5000) == 0) {
                System.out.printf("\t0 - " + k + "\t\t%f\t\t%d\n", ((double)totalIteration / (double)k), maxIteration);
            }
        }
        System.out.printf("\t0 - " + supportedRange + "\t\t%f\t\t%d\n", ((double)totalIteration / (double)supportedRange), maxIteration);
    }

public
    int getNumberFromIndex(int bitIndex)
    {
        return bitIndex * 3 - 1 - (bitIndex % 2);
    }

public
    int getIndexFromNumber(int number)
    {
        int index = number - (number / 2) - (number / 3) + (number / 6);
        return index;
    }
}
#endif
