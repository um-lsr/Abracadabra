#include <iostream>
#include <String.h>
#include <stdio.h>
#include <cstdlib>
#include <codecvt>
#include <random>
#include <Windows.h>
#include <nlohmann/json.hpp>
#include <cppcodec/base64_rfc4648.hpp>
using namespace std;
using json = nlohmann::json;
using base64 = cppcodec::base64_rfc4648;

const string Map = "{\"basic\":{\"alphabet\":{\"a\":[\"请\",\"上\",\"中\",\"之\",\"等\",\"人\",\"到\",\"年\",\"个\",\"将\"],\"b\":[\"得\",\"可\",\"并\",\"发\",\"过\"],\"c\":[\"页\",\"于\",\"而\",\"被\",\"无\"],\"d\":[\"由\",\"把\",\"好\",\"从\",\"会\"],\"e\":[\"的\",\"在\",\"了\",\"是\",\"为\",\"有\",\"和\",\"我\",\"一\",\"与\"],\"f\":[\"站\",\"最\",\"号\",\"及\",\"能\"],\"g\":[\"着\",\"很\",\"此\",\"但\",\"看\"],\"h\":[\"名\",\"呢\",\"又\",\"图\",\"啊\"],\"i\":[\"对\",\"地\",\"您\",\"给\",\"这\",\"下\",\"网\",\"也\",\"来\",\"你\"],\"j\":[\"更\",\"天\",\"去\",\"用\",\"只\"],\"k\":[\"第\",\"者\",\"所\",\"两\",\"里\"],\"l\":[\"自\",\"做\",\"前\",\"二\",\"他\"],\"m\":[\"家\",\"点\",\"路\",\"至\",\"十\"],\"n\":[\"区\",\"想\",\"向\",\"主\",\"四\"],\"o\":[\"就\",\"新\",\"吗\",\"该\",\"不\",\"多\",\"还\",\"要\",\"让\",\"大\"],\"p\":[\"小\",\"如\",\"成\",\"位\",\"其\"],\"q\":[\"吧\",\"每\",\"机\",\"几\",\"总\"],\"r\":[\"起\",\"它\",\"内\",\"高\",\"次\"],\"s\":[\"非\",\"元\",\"类\",\"五\",\"使\"],\"t\":[\"首\",\"进\",\"即\",\"没\",\"市\"],\"u\":[\"后\",\"三\",\"本\",\"都\",\"时\",\"月\",\"或\",\"说\",\"已\",\"以\"],\"v\":[\"种\",\"快\",\"那\",\"篇\",\"万\"],\"w\":[\"长\",\"按\",\"报\",\"比\",\"信\"],\"x\":[\"再\",\"带\",\"才\",\"全\",\"呀\"],\"y\":[\"业\",\"却\",\"版\",\"美\",\"们\"],\"z\":[\"像\",\"走\",\"文\",\"各\",\"当\"]},\"number\":{\"0\":[\"卡\",\"风\",\"水\",\"放\",\"花\"],\"1\":[\"需\",\"头\",\"话\",\"曾\",\"楼\"],\"2\":[\"连\",\"系\",\"门\",\"力\",\"量\"],\"3\":[\"书\",\"亿\",\"跟\",\"深\",\"方\"],\"4\":[\"若\",\"低\",\"谈\",\"明\",\"百\"],\"5\":[\"关\",\"客\",\"读\",\"双\",\"回\"],\"6\":[\"较\",\"品\",\"嘛\",\"单\",\"价\"],\"7\":[\"山\",\"西\",\"动\",\"厂\",\"热\"],\"8\":[\"言\",\"笑\",\"度\",\"易\",\"身\"],\"9\":[\"份\",\"星\",\"千\",\"仍\",\"办\"]},\"symbol\":{\"+\":[\"集\",\"费\",\"传\",\"室\",\"拉\"],\"/\":[\"难\",\"界\",\"指\",\"管\",\"具\"],\"?\":[\"相\",\"儿\",\"李\",\"早\",\"拿\"],\"-\":[\"科\",\"白\",\"段\",\"飞\",\"住\"],\".\":[\"利\",\"红\",\"板\",\"光\",\"约\"],\"(\":[\"变\",\"款\",\"林\",\"夹\",\"院\"],\")\":[\"服\",\"句\",\"声\",\"务\",\"游\"],\"[\":[\"股\",\"南\",\"社\",\"阿\",\"远\"],\"]\":[\"意\",\"换\",\"些\",\"必\",\"赛\"],\"<\":[\"届\",\"完\",\"乐\",\"彩\",\"讲\"],\">\":[\"展\",\"帮\",\"且\",\"物\",\"班\"],\",\":[\"何\",\"流\",\"密\",\"某\",\"房\"],\"|\":[\"语\",\"亚\",\"常\",\"除\",\"装\"],\"=\":[\"极\",\"载\",\"题\",\"刚\",\"气\"],\"@\":[\"米\",\"影\",\"德\",\"世\",\"坐\"],\"#\":[\"北\",\"招\",\"短\",\"活\",\"斯\"],\"!\":[\"值\",\"店\",\"树\",\"哪\",\"余\"],\"~\":[\"盘\",\"速\",\"座\",\"求\",\"创\"],\"`\":[\"梦\",\"足\",\"半\",\"视\",\"安\"],\"$\":[\"空\",\"歌\",\"派\",\"顶\",\"登\"],\"%\":[\"夜\",\"云\",\"感\",\"啦\",\"欲\"],\"^\":[\"边\",\"工\",\"眼\",\"街\",\"奖\"],\"&\":[\"获\",\"占\",\"理\",\"任\",\"实\"],\"*\":[\"知\",\"掉\",\"色\",\"讯\",\"克\"],\"_\":[\"直\",\"评\",\"往\",\"层\",\"园\"],\"{\":[\"留\",\"靠\",\"亦\",\"罗\",\"营\"],\"}\":[\"合\",\"尚\",\"产\",\"诚\",\"汨\"],\":\":[\"曱\",\"朩\",\"杉\",\"杸\",\"歩\"],\";\":[\"毋\",\"氕\",\"気\",\"氘\",\"氙\"],\" \":[\"叧\",\"叺\",\"叻\",\"叾\",\"吅\",\"叿\",\"吙\",\"呡\",\"呤\",\"呮\",\"呭\",\"呾\",\"呟\",\"吂\",\"吤\"],\"\\t\":[\"圠\",\"圡\",\"圢\",\"圤\",\"圥\",\"圦\",\"坆\",\"夨\",\"夨\",\"夬\",\"夳\",\"夶\",\"奀\",\"夻\",\"夼\"],\"\\n\":[\"孒\",\"孖\",\"尐\",\"尛\",\"尢\",\"尣\",\"巛\",\"巜\",\"幷\",\"弐\",\"彑\",\"彡\",\"彳\",\"忄\",\"扖\"]}},\"link\":{\"http\":[\"贴\",\"则\",\"老\",\"生\",\"达\"],\"://\":[\"商\",\"行\",\"周\",\"证\",\"经\"],\"magnet\":[\"事\",\"场\",\"同\",\"化\",\"找\"],\"udp\":[\"建\",\"手\",\"道\",\"间\",\"式\"],\"tcp\":[\"特\",\"城\",\"型\",\"定\",\"接\"],\"ftp\":[\"局\",\"问\",\"重\",\"叫\",\"通\"],\":?xt=urn:btih:\":[\"件\",\"少\",\"面\",\"金\",\"近\"],\"torrent\":[\"买\",\"听\",\"学\",\"见\",\"称\"],\"www\":[\"写\",\"选\",\"片\",\"体\",\"组\"],\"mailto\":[\"先\",\"仅\",\"别\",\"表\",\"现\"]},\"special\":{\"BIG\":[\"未\",\"哦\",\"部\",\"项\",\"谁\",\"分\",\"转\",\"字\",\"数\",\"心\",\"子\",\"处\",\"作\",\"因\",\"设\"],\"TYPE\":{\"LINK\":[\"应畑\",\"的凪\",\"开辺\",\"录込\"],\"NORMAL\":[\"钟込\",\"均桜\",\"错桜\",\"妳桜\"],\"BASE64\":[\"奂込\",\"妍桜\",\"姾凪\",\"娂辺\"],\"DECRYPT\":[\"飞込\",\"电桜\",\"亖凪\",\"冇辺\"]}}}"; //字符串映射表
const json Map_Obj = json::parse(Map); //JSON字符串映射表对象

const string Normal_Characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+=_-/?.>,<|`~!@#$%^&*(){}[];: \n\t1234567890"; //表内有映射的所有字符组成的字符串
const string LETTERS = "abcdefghijklmnopqrstuvwxyz";
const string BIG_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string NUMBERS = "1234567890";
const string SYMBOLS = "+=_-/?.>,<|`~!@#$%^&*(){}[];: \n\t";
const string SIG_LINK = "应畑,的凪,开辺,录込";//链接类型的标志位列表
const string SIG_NORMAL = "钟込,均桜,错桜,妳桜";//普通类型的标志位列表
const string SIG_BASE64 = "奂込,妍桜,姾凪,娂辺";//Base64类型的标志位列表
const string SIG_DECRYPT = "飞込,电桜,亖凪,冇辺";//加密字符串的标志位列表
const string NULL_STR = "孎"; //默认忽略的占位字符，一个生僻字。

struct PreCheckResult { // 专门用来打包传递预检的结果
    string output;
    bool isUnNormal = false; // 判断是否含有特殊符号(表外内容)
    bool isLink = false;
    bool isNormal = false;
    bool isBase64 = false;
    bool isEncrypted = false;
};


string enMap(PreCheckResult input,bool forceLink,bool forceBase64,bool forceDirect);
string deMap(PreCheckResult input);
string FindOriginText(string letter);
string GetCryptedText(string letter);
string GetLinkCryptedText(string text);
string UrlEncode(const string& szToEncode);
string UrlDecode(const string& szToDecode);
std::string GbkToUtf8(const char* src_str);
PreCheckResult preCheck(string input);


int main(int argc, char *argv[]){
    SetConsoleOutputCP(CP_UTF8); //注意，由于使用了Windows.h，这个版本仅能在Windows平台使用。

    string arg1,arg2;
    PreCheckResult input;
    bool l = false, b = false, n = false, d = false;
    string::size_type idx; 
   
    if(argc >= 2){ //读取参数，最多两个
        arg1 = GbkToUtf8(argv[1]);
    }else{
        arg1 = "";
    }
    if(argc >= 3){
        arg2 = GbkToUtf8(argv[2]);
    }else{
        arg2 = ""; 
    }
        
    idx=arg1.find("-h");
    // -h 输出帮助信息
    if (idx != string::npos || argc < 2){
        cout<<"*** Abracadabra v0.1.1 , by SheepChef ***"<<endl;
        cout<<"Usage:"<<endl;
        cout<<"      abracadabra [arg] [input]"<<endl;
        cout<<"input   : a string to process"<<endl;
        cout<<"Arguments :"<<endl;
        cout<<" -l     : Force to encrypt using url mode"<<endl;
        cout<<" -b     : Force to encrypt using base64 mode"<<endl;
        cout<<" -n     : Force to encrypt the input directly"<<endl;
        cout<<" -d     : Force to decrypt the given input"<<endl;
        cout<<" -h     : Print help information"<<endl;
        cout<<"Tips :"<<endl;
        cout<<"      Usually, the mapped string could tell if itself was mapped and what type itself is."<<endl;
        cout<<endl;
        cout<<"      Using base64 to process your string could provide the highest compatibility, "<<endl;
        cout<<"      but may lose efficiency if your input had no non-English characters."<<endl;
        cout<<endl;
        cout<<"      If you are processing links, use link mode could increase the effciency,"<<endl;
        cout<<"      since some common phrases were directly mapped to single characters."<<endl;
        return 0;
        
    }
    
    
    //判断指令参数
    idx=arg1.find("-l"); 
    if (idx != string::npos){
        l = true;
    }
    idx=arg1.find("-b");
    if (idx != string::npos){
        b = true;
    }
    idx=arg1.find("-n");
    if (idx != string::npos){
        n = true;
    }
    idx=arg1.find("-d");
    if (idx != string::npos){
        d = true;
    }
    idx=arg1.find("-");
    if (idx == string::npos){
        PreCheckResult Result;
        Result = preCheck(arg1);

        if(Result.isEncrypted){
            d = true;
        }
        input = Result;
    }else{
        input = preCheck(arg2);
    }


    if(!d){
        cout<<enMap(input,l,b,n)<<endl;
    }else{
        //尝试解密
        cout<<deMap(input)<<endl;
    }


    return 0;
}


PreCheckResult preCheck(string input){
    int size = input.length(); //第一次遍历字符数组的函数，负责判断给定的输入类型。
    string temp,temp2,group;
    string::size_type idx; 
    bool isUnNormal = false; // 判断是否含有特殊符号(表外内容)
    bool isLink = false;
    bool isNormal = false; //如果检查出这个标志位，则默认是未经Base64处理后加密的密文
    bool isBase64 = false;
    bool isEncrypted = false;//如果检查出这个标志位，那么默认这是一串加密之后的密文
    for(int i=0;i<size;){

        int cplen = 1; //该死的C++，处理中文字符贼繁琐
        int cplen2 = 1;
        if((input[i] & 0xf8) == 0xf0) cplen = 4;
        else if((input[i] & 0xf0) == 0xe0) cplen = 3;
        else if((input[i] & 0xe0) == 0xc0) cplen = 2;
        if((i + cplen) > input.length()) cplen = 1;

        if((input[i+cplen] & 0xf8) == 0xf0) cplen2 = 4;
        else if((input[i+cplen] & 0xf0) == 0xe0) cplen2 = 3;
        else if((input[i+cplen] & 0xe0) == 0xc0) cplen2 = 2;
        if((i + cplen + cplen) > input.length()) cplen2 = 1;
        temp = input.substr(i, cplen);

        if(i != size - cplen2){ //一次遍历两个字符，遇到倒数第一个的时候防止越界
            temp2 = input.substr(i+cplen, cplen2);
        }else{
            temp2 = NULL_STR;
        }
        group = temp + temp2;

        idx = Normal_Characters.find(temp);
        if (idx == string::npos){ //如果在表内找不到某个字符
            isUnNormal = true; //判断含有特殊符号

            //判断这个符号是不是标识符，标识符用空字符进行占位操作
            if(SIG_LINK.find(group) != string::npos){

               input.replace(i, cplen ,NULL_STR);
               input.replace(i + cplen, cplen2 ,NULL_STR);
               isLink = true;
               i += cplen;
               continue;
            }
            if(SIG_NORMAL.find(group) != string::npos){

               input.replace(i, cplen ,NULL_STR);
               input.replace(i + cplen, cplen2 ,NULL_STR);
               isNormal = true;
               i += cplen;
               continue;
            }
            if(SIG_BASE64.find(group) != string::npos){

               input.replace(i, cplen ,NULL_STR);
               input.replace(i + cplen, cplen2 ,NULL_STR);
               isBase64 = true;
               i += cplen;
               continue;
            }
            if(SIG_DECRYPT.find(group) != string::npos){

               input.replace(i, cplen ,NULL_STR);
               input.replace(i + cplen, cplen2 ,NULL_STR);
               isEncrypted = true;
               i += cplen;
               continue;
            }
        }
        i += cplen;
    }
    PreCheckResult Result;
    Result.output = input;
    Result.isNormal = isNormal;
    Result.isUnNormal = isUnNormal;
    Result.isEncrypted = isEncrypted;
    Result.isLink = isLink;
    Result.isBase64 = isBase64;

    return Result;
}

string enMap(PreCheckResult input,bool forceLink,bool forceBase64,bool forceDirect){

    string OriginStr = input.output;
    string TempStr1;
    
    string temp,temp2,group;
    string::size_type idx; 


    if(input.isUnNormal && forceDirect){//如果给定的字符串包括特殊字符且指定不处理特殊字符，解决矛盾
        forceDirect = false;
        forceLink = false;
        forceBase64 = true;
    }
    if(forceLink){ //链接模式前置URLencode处理
        OriginStr = GetLinkCryptedText(UrlEncode(input.output));
    }else if(forceBase64){ //Base64模式前置base64处理
        OriginStr = base64::encode(input.output);
    }else if(input.isUnNormal){//包含特殊字符，默认Base64
        OriginStr = base64::encode(input.output);
        forceBase64 = true;
    }


    int size = OriginStr.length();
    for(int i=0;i<size;){
        int cplen = 1; //该死的C++，处理中文字符贼繁琐
        int cplen2 = 1;
        if((OriginStr[i] & 0xf8) == 0xf0) cplen = 4;
        else if((OriginStr[i] & 0xf0) == 0xe0) cplen = 3;
        else if((OriginStr[i] & 0xe0) == 0xc0) cplen = 2;
        if((i + cplen) > OriginStr.length()) cplen = 1;

        if((OriginStr[i+cplen] & 0xf8) == 0xf0) cplen2 = 4;
        else if((OriginStr[i+cplen] & 0xf0) == 0xe0) cplen2 = 3;
        else if((OriginStr[i+cplen] & 0xe0) == 0xc0) cplen2 = 2;
        if((i + cplen + cplen) > OriginStr.length()) cplen2 = 1;
        temp = OriginStr.substr(i, cplen);
        if(i != size - cplen2){ //一次遍历两个字符，遇到倒数第一个的时候防止越界
            temp2 = OriginStr.substr(i+cplen, cplen2);
        }else{
            temp2 = NULL_STR;
        }
        group = temp + temp2;

        //到这儿循环的取字部分就完成了
        //temp是前一个字，temp2是后一个字
        idx = Normal_Characters.find(temp);
        if (idx == string::npos){ //如果在表内找不到某个字符
            TempStr1 = TempStr1 + temp; //把这个字符加到结果字符串的后面
            i += cplen; //直接跳过
            continue;
        }

        //加密操作开始
        TempStr1 = TempStr1 + GetCryptedText(temp); //把加密字符加到结果字符串的后面
        i += cplen;
    }

    //第一个循环结束后，TempStr1应当是完全的密文，但是缺少标志位
    //随机选择一个下标
    random_device rd;
    unsigned int seed = rd();
    mt19937 mt_r(seed);
    uniform_int_distribution<long long> dist(1, 10000);
    int RandIndex,RandIndex2;
    vector<int> Avoid;
    for(int q=0;q<2;q++){//分两次大循环
        vector<int> PosToInset;
        size = TempStr1.length();
        for(int i=0;i<size;){ //这里需要确定所有插入UTF-8字符的合适位置
            int cplen = 1; //该死的C++，处理中文字符贼繁琐
            int cplen2 = 1;
            if((TempStr1[i] & 0xf8) == 0xf0) cplen = 4;
            else if((TempStr1[i] & 0xf0) == 0xe0) cplen = 3;
            else if((TempStr1[i] & 0xe0) == 0xc0) cplen = 2;
            if((i + cplen) > TempStr1.length()) cplen = 1;

            if((TempStr1[i+cplen] & 0xf8) == 0xf0) cplen2 = 4;
            else if((TempStr1[i+cplen] & 0xf0) == 0xe0) cplen2 = 3;
            else if((TempStr1[i+cplen] & 0xe0) == 0xc0) cplen2 = 2;
            if((i + cplen + cplen) > TempStr1.length()) cplen2 = 1;
            i += cplen;
            PosToInset.push_back(i);
        }
        vector<string> CipherArray,CipherArray2;
        int i;
        if(q==0){//第一次大循环插入模式标志位
            RandIndex = PosToInset.at(dist(mt_r) % PosToInset.size());//在所有可插入位置中随便选一个
            if(forceDirect){//无处理特殊字符标志位
                Map_Obj["special"]["TYPE"]["NORMAL"].get_to(CipherArray);
                RandIndex2 = dist(mt_r) % CipherArray.size();//随机获取一个下标
                i = 0;
                for (auto el : Map_Obj["special"]["TYPE"]["NORMAL"]){//遍历列表
                    if(i == RandIndex2){
                        TempStr1.insert(RandIndex,(string)el);
                        string stemp = (string)el;
                        for(int z = RandIndex + 1;z < RandIndex + stemp.length();z++){
                            Avoid.push_back(z);
                        }
                        break;
                    }
                    i++;
                }
            }else if(forceLink){ //链接模式标志位
                Map_Obj["special"]["TYPE"]["LINK"].get_to(CipherArray);
                RandIndex2 = dist(mt_r) % CipherArray.size();//随机获取一个下标
                i = 0;
                for (auto el : Map_Obj["special"]["TYPE"]["LINK"]){//遍历列表
                    if(i == RandIndex2){
                        TempStr1.insert(RandIndex,(string)el);
                        string stemp = (string)el;
                        for(int z = RandIndex + 1;z < RandIndex + stemp.length();z++){
                            Avoid.push_back(z);
                        }
                        break;
                    }
                    i++;
                }
            }else if(forceBase64){ //Base64模式标志位
                Map_Obj["special"]["TYPE"]["BASE64"].get_to(CipherArray);
                RandIndex2 = dist(mt_r) % CipherArray.size();//随机获取一个下标
                i = 0;
                for (auto el : Map_Obj["special"]["TYPE"]["BASE64"]){//遍历列表
                    if(i == RandIndex2){
                        TempStr1.insert(RandIndex,(string)el);
                        string stemp = (string)el;
                        for(int z = RandIndex + 1;z < RandIndex + stemp.length();z++){
                            Avoid.push_back(z);
                        }
                        break;
                    }
                    i++;
                }
            }
        }
        else if(q==1){ // 第二次大循环插入加密标志位
            vector<int> AvailPos;
            AvailPos.resize(max(PosToInset.size(),Avoid.size()));

            vector<int>::iterator itEnd = set_difference(PosToInset.begin(), PosToInset.end(), Avoid.begin(), Avoid.end(), AvailPos.begin());

            AvailPos.erase(std::remove(AvailPos.begin(), AvailPos.end(), 0), AvailPos.end());
            RandIndex = AvailPos.at(dist(mt_r) % AvailPos.size());//在所有可插入位置中随便选一个
            
            Map_Obj["special"]["TYPE"]["DECRYPT"].get_to(CipherArray2);
            RandIndex2 = dist(mt_r) % CipherArray2.size();//随机获取一个下标
            i = 0;
            for (auto el : Map_Obj["special"]["TYPE"]["DECRYPT"]){//遍历列表
                if(i == RandIndex2){
                    TempStr1.insert(RandIndex,(string)el);
                    break;
                }
                i++;
            }
        }
    }
 
    return TempStr1;
}

string deMap(PreCheckResult input){
    string OriginStr = input.output;
    string TempStr1,TempStrz;
    
    string temp,temp2,group,findtemp;
    string::size_type idx; 
    int size = OriginStr.length();
    for(int i=0;i<size;){
        int cplen = 1; //该死的C++，处理中文字符贼繁琐
        int cplen2 = 1;
        if((OriginStr[i] & 0xf8) == 0xf0) cplen = 4;
        else if((OriginStr[i] & 0xf0) == 0xe0) cplen = 3;
        else if((OriginStr[i] & 0xe0) == 0xc0) cplen = 2;
        if((i + cplen) > OriginStr.length()) cplen = 1;

        if((OriginStr[i+cplen] & 0xf8) == 0xf0) cplen2 = 4;
        else if((OriginStr[i+cplen] & 0xf0) == 0xe0) cplen2 = 3;
        else if((OriginStr[i+cplen] & 0xe0) == 0xc0) cplen2 = 2;
        if((i + cplen + cplen) > OriginStr.length()) cplen2 = 1;
        temp = OriginStr.substr(i, cplen);
        if(i != size - cplen2){ //一次遍历两个字符，遇到倒数第一个的时候防止越界
            temp2 = OriginStr.substr(i+cplen, cplen2);
        }else{
            temp2 = NULL_STR;
        }
        group = temp + temp2;

        //到这儿循环的取字部分就完成了
        //temp是前一个字，temp2是后一个字
        if(temp == NULL_STR){ //如果这是空字符
            i+=cplen; 
            continue;
        }else{//如果不是
            TempStrz = TempStrz + temp; //加上
            i+=cplen; 
            continue;
        }
    }
    //TempStrz为去除了标志位/占位符的密文
    size = TempStrz.length();
    OriginStr = TempStrz;


    for(int i=0;i<size;){
        int cplen = 1; //该死的C++，处理中文字符贼繁琐
        int cplen2 = 1;
        if((OriginStr[i] & 0xf8) == 0xf0) cplen = 4;
        else if((OriginStr[i] & 0xf0) == 0xe0) cplen = 3;
        else if((OriginStr[i] & 0xe0) == 0xc0) cplen = 2;
        if((i + cplen) > OriginStr.length()) cplen = 1;

        if((OriginStr[i+cplen] & 0xf8) == 0xf0) cplen2 = 4;
        else if((OriginStr[i+cplen] & 0xf0) == 0xe0) cplen2 = 3;
        else if((OriginStr[i+cplen] & 0xe0) == 0xc0) cplen2 = 2;
        if((i + cplen + cplen) > OriginStr.length()) cplen2 = 1;
        temp = OriginStr.substr(i, cplen);
        if(i != size - cplen2){ //一次遍历两个字符，遇到倒数第一个的时候防止越界
            temp2 = OriginStr.substr(i+cplen, cplen2);
        }else{
            temp2 = NULL_STR;
        }
        group = temp + temp2;

        //到这儿循环的取字部分就完成了
        //temp是前一个字，temp2是后一个字
        findtemp = FindOriginText(temp); //查找第一个字符的原文
        if(findtemp == "BIG"){ //如果这是一个大写标志位
            findtemp = FindOriginText(temp2); //那么找第二个字符的原文
            string BIGA = findtemp;
            BIGA = strupr((char*)BIGA.c_str());
            TempStr1 = TempStr1 + BIGA; //把找到的原文增加到字符串上
            i = i + cplen + cplen2; //跳过两个字段
            continue;
        }else{
            TempStr1 = TempStr1 + findtemp; //把找到的原文增加到字符串上
            i+=cplen; 
            continue;
        }

        
    }
    //到这儿应该能还原出预先处理过的原文

    if(input.isBase64){//如果是Base64加密后的文本，那么解密
    std::vector<uint8_t> TempStr2Int;
    TempStr2Int = base64::decode(TempStr1);
    string TempStr2(TempStr2Int.begin(),TempStr2Int.end());
    return TempStr2;
    } //不进行urldecode


    return TempStr1;
}
string GetLinkCryptedText(string text){//查表，检查是否有任何预配置的关键词
    string s = text; //源文本
    string s1,s2;
    random_device rd;
    unsigned int seed = rd();
    mt19937 mt_r(seed);
    uniform_int_distribution<long long> dist(1, 10000);
    vector<string> CipherArray;
    int RandIndex; 

    for (auto& el : Map_Obj["link"].items()){//遍历关键词列表
        s1 = el.key();
        if(s.find(s1) != string::npos){//找到关键词
            el.value().get_to(CipherArray);
            
            //返回密本中的随机字符
            RandIndex = dist(mt_r) % CipherArray.size(); //随机获取一个下标
            int i = 0 ;
            for (auto it : Map_Obj["link"][s1]){
                if (i == RandIndex){//找到下标
                    s2 = (string)it;
                    break;
                }
                i++;
            }
            while(s.find(s1)<s.size()){
                int pos = s.find(s1);
                s.replace(pos, s1.size(), s2);
            }
        }

    }
    return s;


}
string GetCryptedText(string letter){//查表返回加密之后的字符串
    random_device rd;
    unsigned int seed = rd();
    mt19937 mt_r(seed);
    uniform_int_distribution<long long> dist(1, 10000);

    string::size_type idx,idx2,idx3,idx4; 
    int RandIndex,RandIndex2;

    idx = LETTERS.find(letter); //是否是小写字母
    idx2 = BIG_LETTERS.find(letter); //是否是大写字母
    idx3 = NUMBERS.find(letter); //是否是数字
    idx4 = SYMBOLS.find(letter); //是否是符号
    
    if(idx != string::npos || idx2 != string::npos){//判断给定字符的类型
        string key,keyU;
        for (auto& el : Map_Obj["basic"]["alphabet"].items())
        {
            vector<string> CipherArray;
            vector<string> CipherArrayBIG;
            key = el.key();
            keyU = (string)key;
            if(key == letter){
                el.value().get_to(CipherArray); //把密本存进容器里
                RandIndex = dist(mt_r) % CipherArray.size(); //随机获取一个下标
                int i = 0 ;
                for (auto it : Map_Obj["basic"]["alphabet"][letter]){
                    if (i == RandIndex){
                        return (string)it;
                    }
                    i++;
                }
            }else if(strupr((char*)keyU.c_str()) == letter){//碰到大写字母
                el.value().get_to(CipherArray);
                Map_Obj["special"]["BIG"].get_to(CipherArrayBIG);
                RandIndex = dist(mt_r) % CipherArray.size();
                RandIndex2 = dist(mt_r) % CipherArrayBIG.size();
                int i = 0;
                for (auto it : Map_Obj["basic"]["alphabet"][key]){
                    if (i == RandIndex){//选中小写字符的密文
                        int t=0;
                        for (auto tt : Map_Obj["special"]["BIG"]){
                            if(t == RandIndex2){//随机选一个大写标志位
                                return (string)tt + (string)it; //组合标志位和小写字符密文，返回回去
                            }
                            t++;
                        }
                    }
                    i++;
                }
            }
        }
    }else if(idx3 != string::npos){
        for (auto& el : Map_Obj["basic"]["number"].items())
        {
        vector<string> CipherArray;
        if(el.key() == letter){
            el.value().get_to(CipherArray); //把密本存进容器里
            RandIndex = dist(mt_r) % CipherArray.size(); //随机获取一个下标
            int i = 0 ;
            for (auto it : Map_Obj["basic"]["number"][letter]){
                if (i == RandIndex){
                    return it;
                }
                i++;
            }
        }
        }
    }else if(idx4 != string::npos){
        for (auto& el : Map_Obj["basic"]["symbol"].items())
        {
            vector<string> CipherArray;
            if(el.key() == letter){
                el.value().get_to(CipherArray); //把密本存进容器里
                RandIndex = dist(mt_r) % CipherArray.size(); //随机获取一个下标
                int i = 0 ;
                for (auto it : Map_Obj["basic"]["symbol"][letter]){
                    if (i == RandIndex){
                        return it;
                    }
                    i++;
                }
            }
        }
    }
    return NULL_STR;
}
string FindOriginText(string letter){
    for (auto el : Map_Obj["special"]["BIG"]){
        string str = (string)el;
        if(letter == str){
            return "BIG";
        }
    }
    for (auto& el : Map_Obj["basic"]["alphabet"].items()){
        for (auto ell : el.value()){
            string str = (string)ell;
            if(letter == str){
                return el.key();
            }
        }
    }
    for (auto& el : Map_Obj["basic"]["number"].items()){
        for (auto ell : el.value()){
            string str = (string)ell;
            if(letter == str){
                return el.key();
            }
        }
    }
    for (auto& el : Map_Obj["basic"]["symbol"].items()){
        for (auto ell : el.value()){
            string str = (string)ell;
            if(letter == str){
                return el.key();
            }
        }
    }
    for (auto& el : Map_Obj["link"].items()){
        for (auto ell : el.value()){
            string str = (string)ell;
            if(letter == str){
                return el.key();
            }
        }
    }
    return "";
}
string UrlEncode(const string& szToEncode)
{
	string src = szToEncode;
	char hex[] = "0123456789ABCDEF";
	string dst;
 
 
	for (size_t i = 0; i < src.size(); ++i)
	{
		unsigned char cc = src[i];
		if ( cc >= 'A' && cc <= 'Z' 
                 || cc >='a' && cc <= 'z'
                 || cc >='0' && cc <= '9'
                 || cc == '.'
                 || cc == '_'
                 || cc == '-'
                 || cc == '*'
                 || cc == ':'
                 || cc == '/'
                 || cc == '%'
                 || cc == '?'
                 || cc == '=')
		{
			if (cc == ' ')
			{
				dst += "+";
			}
			else
				dst += cc;
		}
		else
		{
			unsigned char c = static_cast<unsigned char>(src[i]);
			dst += '%';
			dst += hex[c / 16];
			dst += hex[c % 16];
		}
	}
	return dst;
}
string UrlDecode(const string& szToDecode)
{
	string result;
	int hex = 0;
	for (size_t i = 0; i < szToDecode.length(); ++i)
	{
		switch (szToDecode[i])
		{
		case '+':
			result += ' ';
			break;
		case '%':
			if (isxdigit(szToDecode[i + 1]) && isxdigit(szToDecode[i + 2]))
			{
				string hexStr = szToDecode.substr(i + 1, 2);
				hex = strtol(hexStr.c_str(), 0, 16);
				//字母和数字[0-9a-zA-Z]、一些特殊符号[$-_.+!*'(),] 、以及某些保留字[$&+,/:;=?@]
				//可以不经过编码直接用于URL
				if (!((hex >= 48 && hex <= 57) ||	//0-9
					(hex >=97 && hex <= 122) ||	//a-z
					(hex >=65 && hex <= 90) ||	//A-Z
					//一些特殊符号及保留字[$-_.+!*'(),]  [$&+,/:;=?@]
					hex == 0x21 || hex == 0x24 || hex == 0x26 || hex == 0x27 || hex == 0x28 || hex == 0x29
					|| hex == 0x2a || hex == 0x2b|| hex == 0x2c || hex == 0x2d || hex == 0x2e || hex == 0x2f
					|| hex == 0x3A || hex == 0x3B|| hex == 0x3D || hex == 0x3f || hex == 0x40 || hex == 0x5f
					))
				{
					result += char(hex);
					i += 2;
				}
				else result += '%';
			}else {
				result += '%';
			}
			break;
		default:
			result += szToDecode[i];
			break;
		}
	}
	return result;
}
std::string GbkToUtf8(const char* src_str)
{
    std::string result;
    wchar_t* strSrc;
    char* szRes;
    int len = MultiByteToWideChar(CP_ACP, 0, src_str, -1, NULL, 0);
    strSrc = new wchar_t[len + 1];
    MultiByteToWideChar(CP_ACP, 0, src_str, -1, strSrc, len);
 
    len = WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new char[len + 1];
    WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, szRes, len, NULL, NULL);
    result = szRes;
    if (strSrc)
        delete[]strSrc;
    if (szRes)
        delete[]szRes;
    return result;
}