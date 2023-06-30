#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class timestamp {
	protected:
	vector<string> deb;
	vector<string> fin;
vector<string> debetfin(string, int,size_t);
void impr(vector<string> v);

public:
size_t cherch(string s);
		timestamp(string s):
	deb(debetfin(s,-1,cherch(s))), 
	    fin(debetfin(s,1,cherch(s))) 
	{}		
bool compare(); 
virtual void print(){ 
	impr(deb); cout<<" --> "; impr(fin);
	}
};

class replique: public timestamp {
	protected:
string rep;
public:
size_t debRep(string);
size_t finRep(string, size_t);	
replique(string) ;
void print();


	
	};
	replique::replique(string s):
	timestamp(s), rep(s.substr(debRep(s),finRep(s,debRep(s))+1-debRep(s))) {
		//cout<<endl<<"creation d'instance--replique";
		} 
	
size_t replique::debRep(string s){
	//cout<<endl<<"debRep";
	size_t pos(cherch(s)); 
	//apparemment, en string, '\n' vaut 2?
	while (s[pos]!='\n') {//cout<<s[pos]<<"***"<<endl;
		 pos++; }
	return ++pos;
	}
	//stocker posd posf dans des pointeurs statiques?
size_t replique::finRep(string s, size_t pos){
	int ind(0); size_t marq(pos);
	while(ind!=2&&pos!=s.length()) {
		if (s[pos]!='\n'&&s[pos]!=' ') { ind=0; marq=pos; //cout <<s[pos]; 
			}
		if (s[pos]=='\n') { //cout<<"*";
			ind++;}
		pos++; 
	}
	return marq;
	}
void replique::print() {
	this->timestamp::print();
	cout<<endl<<rep<<endl<<endl;
	//cout<<"print fini";
	}
	
bool timestamp::compare() {
	for (int i(0); i<4;i++)
	if (deb[i]!=fin[i]) return false;
	//cout<<"timestamp - compare";
	return true;
	}
	
void timestamp::impr(vector<string> v) {
	cout<<v[0];
	for (int i(1); i<3; i++)
	cout<<":"+v[i];
	cout<<","<<v[3];
	}
size_t timestamp::cherch(string s){
	return s.find("-->");
	}
vector<string> timestamp::debetfin(string s, int n,  size_t pos){
	//cout<<endl<<"debetfin";
	vector<char> v={':',':',','}; vector<string> deb(4,"0"); size_t ind;
	size_t tab; if (n<0) {tab=2; ind=deb.size()-1;} else {tab=0; ind=0;} size_t marq;
	while (!isdigit(s[pos])) pos+=n;
	marq=pos; 
	
	//on arrive Ö la fin ou au dÇbut du timestamp
	//cout<<"pos:"<<pos<<"  "<< "tab:"<<tab<<"   v.size:"<<v.size()<<endl;
	while(pos>=0&&tab>=0&&tab<v.size()) { 
		//cout <<endl<<"while1"<<"   "<<v[tab]<<"  "<<s[pos]<<endl;
		//si ni digit ou app Ö v, on dÇgage en renvoyant -1;
	if (!isdigit(s[pos]) && s[pos]!=v[tab]) { 
		//cout <<"isdigit(s[pos]) || s[pos]!=v[tab]:"<<"   "<<(!isdigit(s[pos]))<<"   "<<(s[pos]!=v[tab])<<"  "<<s[pos]<<"  "<<v[tab]<<endl; 
		return deb; }
	
	if (s[pos]==v[tab]) { 
		//cout<<"dans le if, s[pos]="<<s[pos]<<"min   "<<min(pos,marq)<<endl ; 
		deb[ind]=s.substr(min(pos-n,marq), pos*n-marq*n); 
		//cout <<"deb:"<<ind<<"  "<<deb[ind]<<endl; 
		marq=pos+n; tab+=n; ind+=n;}
	pos+=n;
	//cout<< endl<<"fin du if"<<pos<<"  "<<marq<<s[pos]<<"uuuuuu"<<s[marq]<<endl;
	}
	
	while (pos>=0 && isdigit(s[pos])) {
	pos+=n;
	deb[ind]=s.substr(min(pos-n,marq), pos*n-marq*n);
} 

for (int i(0); i<4;i++) ;
//cout << deb[i]<<":";
//cout<< "***FINI**"<<endl<<endl;
return deb;
	}	

/*	
class blocT: public times tamp {
private:
	string pos;
	string rep;
bool syntaxe(string t);

public: 
blocT(string replique) 


bool syntaxe(string t){
	if (t.length()!=unsigned(12)) return false;
	if (t[2]!=':'||t[5]!=':') return false;
	if (t[8]!=',') return false;
	unsigned int i=0;
	while (i<t.length()){
	if (i==2||i==5||i==8) i++;
	if (!isdigit(t[i])) return false;
	i++;
	}
	return true;
}
	};
	* 
	* */
vector<replique> constit(vector<replique> v, string s) {
	//cout<<"j'suis dans la constit"<<endl; 
	if (v.back().cherch(s)==string::npos) return v;
	replique r(s); //cout<<"replique fbrique dans constit";
	v.push_back(r);  size_t pos(r.finRep(s,r.debRep(s)));
	if (pos>s.length()) return v; else return constit(v,s.erase(0,pos));
	}
void print(vector<replique> v) {
	// j sert Ö corriger les compteurs pour les TS Çgaux;
	size_t j(0);
	for (size_t i(0);i<v.size(); i++) {
		if (!v[i].compare()) { 
		cout<<i-j<<endl;
	v[i].print();
} else j++;
}
	}	
int main() {
	vector<replique> v;
string s=R"(0
00:00:01,300 --> 00:00:07,200
<i>Zankoku na tenshi no youni</i>

1
00:00:07,200 --> 00:00:14,600
<i>Shonen yo shinwa ni nare</i>

2
00:00:18,700 --> 00:00:22,200
Neon Genesis
Evangelion

3
00:00:22,800 --> 00:00:25,900
<i>Aoi kaze ga ima</i>

4
00:00:25,900 --> 00:00:29,600
<i>Mune no door wo tataitemo</i>

5
00:00:29,600 --> 00:00:33,400
<i>Watashidake wo tada mitsumete</i>

6
00:00:33,400 --> 00:00:37,700
<i>Hohoenderu anata</i>

7
00:00:37,700 --> 00:00:40,900
<i>Sotto fureru mono</i>

8
00:00:40,900 --> 00:00:44,700
<i>Motomeru koto ni muchu de</i>

9
00:00:44,700 --> 00:00:48,100
<i>Unmei sae mada shiranai</i>

10
00:00:48,100 --> 00:00:51,300
<i>Itaikena hitomi</i>

11
00:00:52,300 --> 00:00:55,800
<i>Dakedo itsuka kizuku deshou</i>

12
00:00:55,800 --> 00:00:58,600
<i>Sono senaka niwa</i>

13
00:00:59,600 --> 00:01:03,500
<i>Haruka mirai mezasu tameno</i>

14
00:01:03,500 --> 00:01:06,800
<i>Hanega arukoto</i>

15
00:01:07,100 --> 00:01:10,800
<i>Zankoku na tenshi no thesis</i>

16
00:01:10,800 --> 00:01:14,600
<i>Madobe kara yagate tobitatsu</i>

17
00:01:14,600 --> 00:01:18,300
<i>Hotobashiru atsui pathos de</i>

18
00:01:18,300 --> 00:01:22,100
<i>Omoide wo uragiru nara</i>

19
00:01:22,100 --> 00:01:25,800
<i>Kono sora wo daite kagayaku.</i>

20
00:01:25,800 --> 00:01:30,200
<i>Shonen yo shinwa ni nare.</i>

21
00:01:32,230 --> 00:01:36,600
Exact, je me suis arrangÇ avec le comitÇ Ö ce sujet.

22
00:01:36,600 --> 00:01:39,070
La cargaison a quittÇ le port de Sasebo la veille

23
00:01:39,070 --> 00:01:40,860
et devrait maintenant survoler l'ocÇan pacifique.

24
00:01:44,640 --> 00:01:47,240
Un hÇlicoptäre de transport MIG-55 D!

25
00:01:47,240 --> 00:01:50,910
Si on m'avait dit un jour que j'en serai carrÇment le passager...

26
00:01:50,910 --> 00:01:54,680
Merci au ciel de m'avoir donnÇ un ami comme toi,
n'est-ce pas Shinji?

27
00:01:55,750 --> 00:01:59,690
Je me suis dit que vous deviez en avoir marre de vos montagnes.

28
00:01:59,690 --> 00:02:02,420
J'ai donc pensÇ Ö faire cette petite sortie, juste vous et moi!

29
00:02:02,420 --> 00:02:06,590
Waaah, c'est comme un rendez-vous galant avec vous?

30
00:02:06,590 --> 00:02:11,230
J'ai achetÇ cette casquette juste pour l'occasion, hein Misato!

31
00:02:11,230 --> 00:02:13,130
Oó est-ce qu'on se rend?

32
00:02:13,130 --> 00:02:16,260
Nous allons faire une croisiäre dans le Pacifique
sur ce superbe navire.

33
00:02:19,070 --> 00:02:23,240
Wow! Cinq porte-avions et quatre cuirassÇs!
La sacrÇe flotte!

34
00:02:23,240 --> 00:02:26,180
Maintenant je sais que la meilleure chose, c'est d'avoir les bons amis!

35
00:02:26,180 --> 00:02:28,310
C'est áa ton "superbe navire"?

36
00:02:28,310 --> 00:02:29,750
Ouais, il est vraiment splendide!

37
00:02:29,750 --> 00:02:32,040
Il est la fiertÇ des U.N.,
le glorieux porte-avions rÇgulier

38
00:02:32,040 --> 00:02:33,820
"Over the Rainbow"!

39
00:02:33,820 --> 00:02:35,250
Il est Çnorme!

40
00:02:35,250 --> 00:02:38,320
Je suis surprise qu'une telle relique flotte encore sur l'eau.

41
00:02:38,320 --> 00:02:39,690
N'exagÇrez pas.

42
00:02:39,690 --> 00:02:42,630
C'est un modäle d'Çpoque qui date d'avant le Second Impact.

43
00:02:43,760 --> 00:02:46,400
Teh, lÉchez-moi deux minutes!

44
00:02:46,400 --> 00:02:49,270
Je comprends pourquoi cette mÇgäre nous a fait
installer la prise de ce jouet...

45
00:02:49,270 --> 00:02:50,390
...pour que ses mioches s'Çclatent.

46
00:03:00,150 --> 00:03:02,470
Oh! Trop cool ! Trop cool !

47
00:03:02,490 --> 00:03:03,750
Trop cool ! Trop cool !

48
00:03:03,790 --> 00:03:05,810
Trop cool ! Trop cool !

49
00:03:05,830 --> 00:03:06,920
C'est vraiment trop cool!

50
00:03:06,920 --> 00:03:10,080
Màme le plus viril des hommes ne pourrait retenir une larme devant ce spectacle.

51
00:03:11,360 --> 00:03:14,890
Cool! Trop gÇnial, trop gÇnial! AH!

52
00:03:14,890 --> 00:03:17,160
Eh, attends, attends un peu!

53
00:03:22,070 --> 00:03:24,040
Mince!

54
00:03:24,040 --> 00:03:25,900
Reviens! Reviens un peu par lÖ!

55
00:03:29,980 --> 00:03:31,680
<i>Hello</i>, Misato.

56
00:03:31,680 --> 00:03:33,980
Comment tu vas depuis le temps?

57
00:03:33,980 --> 00:03:36,850
Tout baigne. 
Toi, tu as clairement grandi.

58
00:03:36,850 --> 00:03:37,620
pas qu'un peu!

59
00:03:37,620 --> 00:03:41,320
Je ne suis pas juste plus grande, 
ma silhouette s'est aussi affinÇe!

60
00:03:41,320 --> 00:03:42,690
Laissez-moi vous prÇsenter.

61
00:03:42,690 --> 00:03:47,060
VoilÖ le pilote de l'unitÇ 02,
le Pupille Deuxiäme,

62
00:03:47,060 --> 00:03:49,050
Sohryu Asuka Langley.

63
00:03:51,350 --> 00:03:51,800
Episode 8
<i> </i>
<i> </i>

64
00:03:51,800 --> 00:03:52,330
Episode 8
Asuka
<i> </i>

65
00:03:52,330 --> 00:03:53,500
Episode 8
Asuka dÇbarque au Japon

66
00:03:53,900 --> 00:03:55,390
Mais pourquoi t'as fait áa?!

67
00:03:57,340 --> 00:03:59,810
C'est le prix du ticket.
Une sacrÇe affaire, n'est-ce pas?

68
00:03:59,810 --> 00:04:03,440
Quoi? Äa valait le coup?!
Alors, regarde un peu celle-lÖ!

69
00:04:05,450 --> 00:04:06,940
Mais il lui arrive quoi?!

70
00:04:08,580 --> 00:04:12,050
Bon, oó est le fameux Pupille Troisiäme!

71
00:04:12,050 --> 00:04:13,950
Ne me dis pas que c'est lui.

72
00:04:13,950 --> 00:04:17,090
Pas d'inquiÇtude, le voici.

73
00:04:17,090 --> 00:04:20,290
Hmm, je m'attendais Ö mieux.

74
00:04:20,290 --> 00:04:24,900
Je suis rassurÇ, je pensais que vous Çtiez le chef de cette bande de garnements,

75
00:04:24,900 --> 00:04:28,300
mais je vois que je m'Çtais visiblement trompÇ.

76
00:04:28,300 --> 00:04:31,600
je vous remercie de votre comprÇhension, Capitaine.

77
00:04:31,600 --> 000:04:32,600
Je vous en prie.

78
00:04:32,600 --> 00:04:37,540
Merci Ö vous de me permettre de revivre la magnifique expÇrience de la garde d'enfants.

79
00:04:37,540 --> 00:04:40,220
Pour votre assistance dans le transport maritime l'UNITê-02,

80
00:04:40,220 --> 00:04:42,150
permettez-moi d'exprimer notre reconnaissance.

81
00:04:42,150 --> 00:04:45,310
VoilÖ les spÇcifications de la prise d'alimentation de secours.

82
00:04:46,450 --> 00:04:48,350
Si vous croyez que j'approuverai jamais une demande

83
00:04:48,350 --> 00:04:51,490
d'activation en pleine mer de votre pantin.

84
00:04:51,490 --> 00:04:56,100
Et si vous voyiez cela comme
une simple prÇcaution pour les cas d'urgence?

85
00:04:56,100 --> 00:05:01,300
C'est pour ces cas d'urgences que la Flotte du Pacifique a ÇtÇ employÇe.

86
00:05:01,300 --> 00:05:05,570
Quand est-ce que les U.N. ont dÇcidÇ nous transformer
en service de transport de cargaison?

87
00:05:05,570 --> 00:05:09,540
Je crois que c'est arrivÇ juste apräs la crÇation d'une certaine organisation.

88
00:05:09,540 --> 00:05:12,540
ProtÇger un jouet, voilÖ un projet grandiose,

00:05:12,540 --> 00:05:15,040
digne d'invoquer la flotte du Pacifique dans son entier!

89
00:05:15,040 --> 00:05:18,680
Je dirais que ce n'est pas assez, si on considäre l'importance d'une EVA.

90
00:05:18,680 --> 00:05:20,490
Si vous voulez bien signez ce document.

91
00:05:20,490 --> 00:05:23,820
Pas encore. Nous avons ÇtÇ chargÇs par la Troisiäme Section d'Allemagne

92
00:05:23,820 --> 00:05:26,960
veiller sur l'EVA-02 et sur son pilote.

93
00:05:26,960 --> 00:05:29,000
Je ne peux pas vous laisser faire comme bon vous semble.

94
00:05:29,000 --> 00:05:31,190
Alors, quand nous cÇderez-vous le commandement?

95
00:05:31,190 --> 00:05:33,670
Une fois que nous aurons accostÇ Ö
New Yokosuka.

96
00:05:33,670 --> 00:05:36,400
La mer est notre jurisdiction.

97
00:05:36,400 --> 00:05:38,340
Ici, vous suivrez nos ordres.

98
00:05:38,340 --> 00:05:39,970
Entendu.

99
00:05:39,970 --> 00:05:44,220
Cependant, je dois vous rappeler qu'en cas d'urgence,
l'autoritÇ de la NERV outrepasse la votre,

100
00:05:44,220 --> 00:05:45,710
et ce en tout point.

101
00:05:45,710 --> 00:05:48,920
-La classe!
-Elle me fait penser Ö Ritsuko.

102
00:05:47,380 --> 00:05:48,920

103
00:05:48,920 --> 00:05:51,480
Ah, tu n'as jamais ÇtÇ aussi gallante.

104
00:05:51,480 --> 00:05:52,680
Kaji!

105
00:05:54,950 --> 00:05:59,560
M. Kaji! Pour la derniäre fois, on ne rentre pas
sur le pont comme dans un salon.

106
00:05:58,120 --> 00:05:59,560
<i>Oh, mes excuses. </i>

107
00:05:59,860 --> 00:06:00,990
<i>Eh bien, veuillez-nous excusez. Transportez nous Ö
New Yokosuka comme prÇvu.</i>

108
00:06:00,990 --> 00:06:03,200
C'est vraiment un rendez-vous?
<i>Eh bien, veuillez-nous excusez. Transportez nous Ö
New Yokosuka comme prÇvu.</i>

109
00:06:03,200 --> 00:06:04,960
Trop Cool! Cool Ö en crever!
<i>Eh bien, veuillez-nous excusez. Transportez nous Ö
New Yokosuka comme prÇvu.</i>

110
00:06:04,960 --> 00:06:08,670
<i> Shit! </i>Ces mioches vont vraiment sauver le monde?

111
00:06:08,670 --> 00:06:10,840
Les temps ont changÇ.

112
00:06:10,840 --> 00:06:14,070
J'ai cru comprendre que le Congräs a placÇ tous ses espoirs sur ce robot.

113
00:06:14,070 --> 00:06:17,680
Sur ce pantin? Les abrutis!

114
00:06:17,680 --> 00:06:21,240
S'ils ont de l'argent Ö gaspiller sur ce truc, ils pourraient au moins nous en filer avant.

115
00:06:25,850 --> 00:06:28,750
Qu'est-ce que tu fabriques ici?!

116
00:06:28,750 --> 00:06:30,390
Je suis son accompagnateur.

117
00:06:30,390 --> 00:06:32,560
Je reviens d'un voyage d'affaires en Allemagne.

118
00:06:32,560 --> 00:06:37,000
Mince, j'ai baissÇ ma garde. J'aurais dñ anticiper une situation pareille.

119
00:06:37,000 --> 00:06:38,860
-HÇ! Me touche pas!
-HÇ! Me touche pas!

120
00:06:38,860 --> 00:06:40,370
-Mais j'y peux rien!
-Mais j'y peux rien!

121
00:06:40,370 --> 00:06:42,000
<i>L'Escouade 3 manoeuvrera Ö l'heure prÇvue.</i>
<i> </i>

122
00:06:42,000 --> 00:06:42,840
<i>L'Escouade 3 manoeuvrera Ö l'heure prÇvue.</i>
<i>Mon Dieu, pourquoi es-tu si froide?</i>

123
00:06:42,840 --> 00:06:42,970
<i> </i>
<i>Mon Dieu, pourquoi es-tu si froide?</i>

124
00:06:42,970 --> 00:06:43,670
Est-ce que tu vois quelqu'un en ce moment
<i>Mon Dieu, pourquoi es-tu si froide?</i>

125
00:06:43,670 --> 00:06:45,810
Est-ce que tu vois quelqu'un en ce moment
<i>Parce la flamme de ton coeur s'est Çteinte.</i>

126
00:06:45,810 --> 00:06:45,940
Est-ce que tu vois quelqu'un en ce moment
<i>∑ l'extÇrieur l'ÇtÇ est brñlant, au-delÖ de 100 degrees.</i>

127
00:06:45,940 --> 00:06:48,340
Je ne vois pas en quoi áa te regarde, si?
<i>∑ l'extÇrieur l'ÇtÇ est brñlant, au-delÖ de 100 degrees.</i>

128
00:06:48,340 --> 00:06:48,810
Pourquoi si cruelle?
<i>∑ l'extÇrieur l'ÇtÇ est brñlant, au-delÖ de 100 degrees.</i>

129
00:06:48,810 --> 00:06:50,940
Pourquoi si cruelle?
<i>Quel est ce froid glacial?</i>

130
00:06:50,940 --> 00:06:51,710
<i>Mon coeur est plus froid que la glace.</i>

131
00:06:51,710 --> 00:06:52,380
Tu vis avec Katsuragi en ce moment, non?
<i>Mon coeur est plus froid que la glace.</i>

132
00:06:52,380 --> 00:06:54,280
Tu vis avec Katsuragi en ce moment, non?
<i>Ma biäre est gelÇe. Il me faut un manteau.</i>

133
00:06:54,280 --> 00:06:55,780
Oui.
<i>Ma biäre est gelÇe. Il me faut un manteau.</i>

134
00:06:55,780 --> 00:06:56,120
Oui.
<i>Ton coeur a trop d'air conditionnÇ.</i>

135
00:06:56,120 --> 00:06:58,520
Dis-moi, est-ce qu'elle est toujours aussi...agitÇe au lit?
<i>Ton coeur a trop d'air conditionnÇ.</i>

136
00:06:58,520 --> 00:06:59,390
Dis-moi, est-ce qu'elle est toujours aussi...agitÇe au lit?
<i>et si tu montais la tempÇrature?</i>

137
00:06:59,390 --> 00:07:02,120
<i>et si tu montais la tempÇrature?</i>

138
00:07:02,120 --> 00:07:02,190
<i>C'est toi, mon climatiseur.</i>

139
00:07:02,190 --> 00:07:03,290
Que...que ...
<i>C'est toi, mon climatiseur.</i>

140
00:07:03,290 --> 00:07:04,290
Que...que ...
<i>Tu es tellement bàte, Ö ventiler la chaleur par l'extÇrieur.</i>

141
00:07:04,290 --> 00:07:05,990
Qu'est-ce que t'essaies d'insinuer?!
<i>Tu es tellement bàte, Ö ventiler la chaleur par l'extÇrieur.</i>

142
00:07:05,990 --> 00:07:06,090
Qu'est-ce que t'essaies d'insinuer?!
<i>Plus tu ventiles et plus mon coeur est froid.</i>

143
00:07:06,090 --> 00:07:07,130
<i>Plus tu ventiles et plus mon coeur est froid.</i>

144
00:07:07,130 --> 00:07:07,990
Ah, elle n'a pas changÇ! N'est-ce pas, Ikari Shinji?
<i>Plus tu ventiles et plus mon coeur est froid.</i>

145
00:07:07,990 --> 00:07:09,700
Ah, elle n'a pas changÇ! N'est-ce pas, Ikari Shinji?
<i>Alors, rÇchauffons ton corps frigorifiÇ ensemble!</i>

146
00:07:09,700 --> 00:07:11,130
Non...
<i>Alors, rÇchauffons ton corps frigorifiÇ ensemble!</i>

147
00:07:11,130 --> 00:07:11,260
Non...
<i>Je suis dÇsolÇe, tu ne peux pas allumer mon feu,</i>

148
00:07:11,260 --> 00:07:13,730
Mais...comment connaissez-vous mon nom?
<i>Je suis dÇsolÇe, tu ne peux pas allumer mon feu,</i>

149
00:07:13,730 --> 00:07:14,300
Impossible de ne pas le connaåtre!
<i>Je suis dÇsolÇe, tu ne peux pas allumer mon feu,</i>

150
00:07:14,300 --> 00:07:15,270
Impossible de ne pas le connaåtre!
<i>Mets des bñches dans mon feu, et ravive-moi Ö l'huile.</i>

151
00:07:15,270 --> 00:07:17,100
Tout le monde ne parle que de toi, dans mon milieu.
<i>Mets des bñches dans mon feu, et ravive-moi Ö l'huile.</i>

152
00:07:17,100 --> 00:07:18,070
Tout le monde ne parle que de toi, dans mon milieu.
<i>Qui est-ce? Je n'y crois pas... C'est ce mec?</i>

153
00:07:18,070 --> 00:07:21,670
Le Troisiäme Pupille, qui a sautÇ au combat dans une EVA sans le moindre entraånement.
<i>Qui est-ce? Je n'y crois pas... C'est ce mec?</i>

154
00:07:21,670 --> 00:07:21,940
Le Troisiäme Pupille, qui a sautÇ au combat dans une EVA sans le moindre entraånement.
<i>Non, c'est ce chiot.</i>

155
00:07:21,940 --> 00:07:22,640
<i>Non, c'est ce chiot.</i>

156
00:07:23,910 --> 00:07:25,610
J'ai juste eu de la chance.
<i>Tu me dis que j'ai perdu contre ce chien?</i>

157
00:07:25,610 --> 00:07:28,350
Cette chance fait partie de ta destinÇe- c'est ton talent.
<i>Tu me dis que j'ai perdu contre ce chien?</i>

158
00:07:28,350 --> 00:07:29,280
Cette chance fait partie de ta destinÇe- c'est ton talent.
<i>Oui, c'est une brave bàte.</i>

159
00:07:29,280 --> 00:07:29,980
<i>Oui, c'est une brave bàte.</i>

160
00:07:29,980 --> 00:07:31,520
Bon, on se voit plus tard.
<i>et il est fidäle, pas comme certains!</i>

161
00:07:31,520 --> 00:07:32,150
D'accord.
<i>et il est fidäle, pas comme certains!</i>

162
00:07:32,150 --> 00:07:33,880
Äa doit àtre une mauvaise blague.
Non, un cauchemar.

163
00:07:36,890 --> 00:07:39,060
Alors, ce Shinji Ikari t'inspire quoi?

164
00:07:39,060 --> 00:07:40,330
Il est barbant.

165
00:07:40,330 --> 00:07:43,730
C'est vraiment lui, le Troisiäme Pupille? 
Quelle dÇception.

166
00:07:43,730 --> 00:07:48,330
Et pourtant, son <i>synchro ratio</i> dÇpassait aisÇment les 40% en plein combat et ce, sans entrainement.

167
00:07:48,330 --> 00:07:50,040
Pas vrai!

168
00:07:50,040 --> 00:07:52,840
L'attitude du capitaine me tape sur les nerfs.

169
00:07:52,840 --> 00:07:54,840
C'est un homme plein de fiertÇ.

170
00:07:54,840 --> 00:07:57,510
Toute cette fiertÇ ne peut que rendre le cynique devant nous.

171
00:07:57,510 --> 00:08:00,880
Il a l'air plutìt charmant, ce M. Kaji.

172
00:08:00,880 --> 00:08:03,380
Il a pas changÇ d'un poil! Ce pauv' dÇbile.

173
00:08:03,380 --> 00:08:04,780
HÇ, le Troisiäme!

174
00:08:06,150 --> 00:08:07,480
Viens avec moi!

175
00:08:15,560 --> 00:08:19,100
L'unitÇ 02 est rouge? J'en avais aucune idÇe.

176
00:08:19,100 --> 00:08:22,340
Sa couleur n'est pas la seule diffÇrence.

177
00:08:22,340 --> 00:08:24,340
Les unitÇs 00 et 01 n'Çtaient que les Çtapes

178
00:08:24,340 --> 00:08:27,510
nÇcessaires Ö tout dÇveloppement,
le <i>Prototype</i> et le <i>modäle d'essai</i>.

179
00:08:27,510 -->  00:08:30,760
Que cette derniäre a pu se synchroniser aussi facilement avec un bleu comme toi

180
00:08:30,760 --> 00:08:32,450
en est la preuve.

181
00:08:32,450 --> 00:08:34,880
Cependant, l'unitÇ 02 n'est pas pareille.

182
00:08:34,880 --> 00:08:37,050
CrÇe pour affronter de vÇritables situations de combat,

183
00:08:37,050 --> 00:08:40,220
elle est la premiäre vraie êvangÇlion au monde.

184
00:08:40,220 --> 00:08:41,710
Le modäle ultime!

185
00:08:44,120 --> 00:08:45,520
C'&tait quoi?

186
00:08:45,520 --> 00:08:48,190
Une onde de choc sous-marine!

187
00:08:48,190 --> 00:08:49,700
Quelque chose a explosÇ pas loin!

188
00:08:51,400 --> 00:08:52,460
Serait-ce...?

189
00:08:56,370 --> 00:08:57,940
...c'est pas vrai, un Ange?!

190
00:08:57,940 --> 00:08:59,800
Quoi, un vrai?

191
00:09:01,710 --> 00:09:04,970
C'est pas bon! Il faut retourner voir Misato.

192
00:09:07,150 --> 00:09:08,510
<i>Chance!</i>

193
00:09:08,800 --> 00:09:10,200
Neon Genesis
Evangelion

194
00:09:14,320 --> 00:09:17,620
<i>∑ tous les navires, maintenez la formation,</i>
<i>et entamez des mesures d'Çvasion!</i>

195
00:09:17,620 --> 00:09:19,220
Rapport gÇnÇral!

196
00:09:19,220 --> 00:09:23,430
<i>Le Cymbeline ne donne plus signe de vie.</i>
<i>Le Titus Andronicus n'arrive pas Ö localiser la cible!</i>

197
00:09:23,430 --> 00:09:26,160
Bon sang! mais il se passe quoi lÖ-bas!

198
00:09:26,160 --> 00:09:28,775
Bonjour, ici la NERV.
DÇsirez-vous obtenir des informations 


200
00:09:28,775 --> 00:09:31,800
concernant l'ennemi
et les mesures de contre-attaques Ö lui rÇpliquer?

201
00:09:31,800 --> 00:09:34,700
C'est une situation de combat!
Seul le personnel autorisÇ est admis ici!

202
00:09:34,700 --> 00:09:38,370
Ce n'est que mon opinion, mais je dirais que nous sommes confrontÇs Ö une attaque d'Ange.

203
00:09:38,370 --> 00:09:40,380
∑ tous les navires, tir Ö volontÇ!

204
00:09:40,380 --> 00:09:41,660
Vous perdez votre temps.

205
00:09:51,800 --> 00:09:55,150
Ce genre d'attaque ne passera jamais son AT-Field.

206
00:09:55,760 --> 00:09:58,560
Que peut bien faire un Ange ici?

207
00:09:58,560 --> 00:09:60,430
Mon Dieu, l'unitÇ 02?

208
00:10:03,330 --> 00:10:05,030
Oó est-ce que tu m'amänes?

209
00:10:07,070 --> 00:10:09,910
Attends ici juste une seconde.

210
00:10:09,910 --> 00:10:11,370
Elle fiche quoi, encore...

211
00:10:19,650 --> 00:10:22,080
Ne regarde pas, espäce de voyeur!

212
00:10:20,150 --> 00:10:21,150
Pardon!

213
00:10:22,080 --> 00:10:25,080
Pourquoi tous les garáons se comportent commes des dÇpravÇs?

214
00:10:32,800 --> 00:10:34,520
Asuka, c'est parti.

215
00:10:41,670 --> 00:10:42,940
Pourquoi il coule pas?!

216
00:10:42,940 --> 00:10:45,340
Je le savais, seule une EVA peut le battre!

217
00:10:51,350 --> 00:10:53,680
Allons-y.

218
00:10:53,680 --> 00:10:56,170
Tu vas m'accompagner!

219
00:10:58,350 --> 00:11:01,960
HÇ, qu'est-ce qu'on fabrique avec des combinaisons d'entry plug?

220
00:11:01,960 --> 00:11:03,290
t'es bàte ou quoi?

221
00:11:03,290 --> 00:11:06,460
On va le battre!
Et mon unitÇ 02 va rendre áa possible!

222
00:11:07,960 --> 00:11:10,970
Pas possible! Misato t'a donnÇ son accord?

223
00:11:10,970 --> 00:11:12,900
J'aurai la permission une fois que je l'aurai battu.

224
00:11:15,700 --> 00:11:20,540
Maintenant, laisse-toi Çblouir par mes magnifiques prouesses de pilote!

225
00:11:20,540 --> 00:11:22,640
Surtout, ne me dÇrange pas.

226
00:11:27,950 --> 00:11:30,890
C'est bizarre. On dirait qu'il est Ö la recherche de quelque chose.

227
00:11:31,920 --> 00:11:34,120
Je ne m'attendais pas Ö voir un Ange ici.

228
00:11:34,120 --> 00:11:36,020
Les choses ne sont pas comme tu as annoncÇ.

229
00:11:36,020 --> 00:11:37,990
<i>VoilÖ la raison de l'UNITê-02 ici,</i>

230
00:11:37,990 --> 00:11:40,560
<i>et je t'ai gÇnÇreusement fourni</i>
<i>un deuxiäme pilote en guise de rÇserve.</i>

231
00:11:41,300 --> 00:11:45,800
<i>Si le pire vient Ö arriver,</i>
<i>Çchappe-toi par tes propres moyens.</i>

232
00:11:45,800 --> 00:11:46,860
C'est compris.

233
00:11:49,620 --> 00:11:51,813
L.C.L. FÅllung!
<i>[Remplissage du L.C.L.!]</i>

234
00:11:51,820 --> 00:11:53,613
Anfang der Bewegung!
<i>[Initiation de la sÇquence de dÇmarrage]</i>

235
00:11:54,020 --> 00:11:56,454
Anfang des Nervenanschlusses!
<i>[Connection de l'interface neuronale!]</i>

236
00:11:56,860 --> 00:11:59,860
Auslîsen von Linksneigung!
<i>[DÇblocage de la pince gauche]</i>

237
00:11:59,860 --> 00:12:01,888
Synchro, Start!

238
00:12:05,590 --> 00:12:07,560
<i>Program error</i>? Qu'est-ce qui cloche?

239
00:12:07,560 --> 00:12:10,460
De la pensÇe parasite!
Je t'ai dit de ne pas me gàner.

240
00:12:10,460 --> 00:12:11,490
Comment áa?

241
00:12:11,490 --> 00:12:15,860
Tu penses en japonais, n'est-ce pas?
Essaie de penser en allemand!

242
00:12:15,860 --> 00:12:19,700
Euh, d'accord. Baumkuchen...

243
00:12:19,700 --> 00:12:21,760
CrÇtin! Laisse tomber.

244
00:12:21,760 --> 00:12:24,960
RÇinitialisatiton de la langue. 
Passage au Japonais courant.

245
00:12:27,940 --> 00:12:31,210
EVANGELION, UNITê-02, activation.

246
00:12:31,210 --> 00:12:34,180
<i>Message venant d'Othello: </i>
<i>"UNITê-02, en plein processus d'activation"</i>

247
00:12:34,180 --> 00:12:35,250
Qu'est-ce que c'est?

248
00:12:35,250 --> 00:12:36,580
<i> Nice</i>, Asuka!

249
00:12:39,190 --> 00:12:42,690
Non! Interrompez la sÇquence d'activation!
Reinitialisez-la!

250
00:12:42,690 --> 00:12:44,730
Ne l'Çcoute pas, Asuka! Donne-tout!

251
00:12:44,730 --> 00:12:47,820
Pardon?! L'EVA et ses
pilotes doivent nous obÇir,

252
00:12:47,820 --> 00:12:50,100
autremement, c'est une violation de la chaåne de commandement!

253
00:12:50,100 --> 00:12:52,190
Qu'est-ce que vous racontez?
C'est clairement une urgence!

254
000:12:52,190 --> 0:12:53,970
Retournez bronzer sur le pont de votre rafiot!

255
00:12:53,970 --> 00:12:56,440
-Vous et vos procÇdures!
-Sale sorciäre...

256
00:12:54,800 --> 00:12:56,440
Vous àtes sÇrieuses?!

257
00:12:56,440 --> 00:12:59,240
Vous àtes au courant que l'unitÇˇ02 est encore en type-B?

258
00:12:59,240 --> 00:13:01,640
Si on tombe dans la mer,
on est fichus!

259
00:13:01,640 --> 00:13:03,250
alors, il suffit de ne pas tomber.

260
00:13:03,250 --> 00:13:04,880
Shinji, toi aussi tu es lÖ?

261
00:13:04,880 --> 00:13:05,680
Oui.

262
00:13:05,680 --> 00:13:06,380
Les deux gamins?
Oui.

263
00:13:06,380 --> 00:13:07,180
Les deux gamins?
<i> </i>

264
00:13:07,180 --> 00:13:09,020
C'est une opportunitÇ ràvÇe...

265
00:13:09,020 --> 00:13:10,380
Asuka! DÇpart!

266
00:13:12,890 --> 00:13:13,820
Il arrive!

267
00:13:13,820 --> 00:13:15,310
On y va!

268
00:13:22,300 --> 00:13:23,170
Il est oó?

269
00:13:23,170 --> 00:13:24,430
par lÖ!

270
00:13:25,430 --> 00:13:27,040
Il nous reste que 58 secondes de courant!

271
00:13:27,040 --> 00:13:28,000
Je sais träs bien!

00:13:28,000 --> 00:13:28,860
Misato?

272
00:13:28,860 --> 00:13:32,270
Amäne la prise d'alimentation externe sur le pont d'envol.

273
00:13:32,270 --> 00:13:33,280
Je m'en occupe.

274
00:13:33,280 --> 00:13:34,610
Qu'est-ce que vous manigancez?!

275
00:13:34,610 --> 00:13:36,210
Allez, en avant!

276
00:13:36,210 --> 00:13:37,700
En avant?

277
00:13:40,750 --> 00:13:42,240
-Courez!
-Fuyez!

278
00:13:55,230 --> 00:13:56,670
<i>La prise est en place!</i>

279
00:13:56,670 --> 00:13:58,600
<i>Connexion au rÇacteur, achevÇe!</i>

280
00:13:58,600 --> 00:14:01,940
<i>Le pont est pràt pour l'atterissage de l'Eva!</i>

281
00:14:01,940 --> 00:14:03,940
∑ tout l'Çquipage,
accrochez-vous avant impact!

282
00:14:03,940 --> 00:14:04,970
C'est insensÇ!

283
00:14:04,970 --> 00:14:05,440
EVA-02, atterrissage imminent!!

284
00:14:05,440 --> 00:14:07,240
EVA-02, atterrissage imminent!!
<i> </i>

285
00:14:17,420 --> 00:14:18,890
Quel gÉchis!

286
00:14:18,890 --> 00:14:21,560
<i>La cible approche Ö toute vitesse!</i>

287
00:14:21,560 --> 00:14:23,560
Il arrive! ∑ 9 heures!

288
00:14:23,560 --> 00:14:25,250
Branchement de l'alimentation externe!

289
00:14:28,800 --> 00:14:30,200
<i>Branchement, terminÇ.</i>

290
00:14:31,500 --> 00:14:32,730
Mais on a pas de fusil.

291
00:14:32,730 --> 00:14:34,290
Le prog knife devrait suffire.

292
00:14:43,150 --> 00:14:44,450
Il est plus gros que je pensais.

293
00:14:44,450 --> 00:14:45,830
Je m'Çtais dis la màme chose!

294
00:14:48,050 --> 00:14:49,450
Qu'est-ce qu'ils comptent faire?!

295
00:14:49,450 --> 00:14:52,320
Le combat au corps-Ö-corps est le moyen le plus efficace de battre les Anges.

296
00:15:05,300 --> 00:15:06,800
Asuka, tu m'Çpates!

297
00:15:06,800 --> 00:15:09,930
Vous vous croyez oó ?!
Regardez le foutoir que vous avez causÇ sur le pont!

298
00:15:17,110 --> 00:15:18,680
Vous voyez comme moi, elle coule!

299
00:15:18,680 --> 00:15:19,550
Asuka!

300
00:15:19,550 --> 00:15:22,480
Se battre sous l'eau est impensable
avec un equipment de type-B !

301
00:15:22,480 --> 00:15:25,310
On ne saura jamais, sauf si on essaie!

302
00:15:43,870 --> 00:15:45,770
Quel gÉchis!

303
00:15:45,770 --> 00:15:47,070
Combien avant que le cÉble se termine?

304
00:15:48,340 --> 00:15:49,980
Encore 1,200 mätres!

305
00:15:49,980 --> 00:15:51,550
Qu'est-ce que vous allez faire?

306
00:15:51,550 --> 00:15:53,550
Nous avons les moyens de le battre.

307
00:15:53,550 --> 00:15:54,950
Je vais devoir agir.

308
00:15:58,950 --> 00:16:01,580
Le cable va arràter de donner!
Accrochez-vous!

309
00:16:07,530 --> 00:16:08,500
Mince!

310
00:16:08,500 --> 00:16:10,300
<i>L'Eva a ratÇ la cible!</i>

311
00:16:10,300 --> 00:16:13,100
C'est bien le moment de... changer le disque.

312
00:16:13,100 --> 00:16:15,970
Wah! Un Yak 38 customisÇ!

313
00:16:15,970 --> 00:16:17,910
<i>HÇ, Katsuragi!</i>

314
00:16:17,910 --> 00:16:19,740
Kaji!

315
00:16:19,740 --> 00:16:22,470
J'ai un paquet Ö livrer.
Je vais devoir vous laisser.

316
00:16:24,480 --> 00:16:26,250
Vous pouvez dÇcoller!

317
00:16:26,250 --> 00:16:28,980
<i>Rägle-lui son compte,</i>
<i>‚ Captain Katsuragi.</i>

318
00:16:30,990 --> 00:16:32,790
Il s'est enfui. J'y crois pas.

319
00:16:32,790 --> 00:16:34,980
<i>La cible s'approche de l'EVA</i>
<i>Ö nouveau!</i>

320
00:16:36,020 --> 00:16:37,660
Il revient!

321
00:16:37,660 --> 00:16:39,350
Je vais m'occuper de lui, cette fois.

322
00:16:43,170 --> 00:16:45,370
Quoi?! Elle ne fonctionne plus!

323
00:16:45,370 --> 00:16:46,900
Ö cause de l'Çquipement B....

324
00:16:46,900 --> 00:16:49,600
-Tu comptes faire quoi, alors?!
-Qu'est-ce que je compte faire?

325
00:16:49,600 --> 00:16:52,670
T'es le Troisiäme Pupille, non?
Bouge-toi les fesses!

326
00:16:52,670 --> 00:16:53,470
Le voilÖ!

327
00:16:58,180 --> 00:16:59,780
Une gueule?!

328
00:16:59,780 --> 00:17:01,250
C'est bien un Ange, pas de doute...

329
00:17:03,950 --> 00:17:06,760
<i>L'EVA 02 viens d'entrer</i>
<i>dans le corps de la cible.</i>

330
00:17:06,760 --> 00:17:08,660
Cela veut-il dire que l'EVA vient d'àtre mangÇ?

331
00:17:10,890 --> 00:17:13,130
C'est comme de la pàche!

332
00:17:13,130 --> 00:17:15,490
De la pàche? Mais oui bien sñr!

333
00:17:17,830 --> 00:17:19,700
les choses vont de mal en pis...

334
00:17:19,700 --> 00:17:20,930
La ferme!

335
00:17:21,940 --> 00:17:24,270
HÇ, arràte de me coller,
sale pervers!

336
00:17:24,270 --> 00:17:26,270
Mais ils faut qu'on se libäre!

337
00:17:26,270 --> 00:17:27,780
Asuka, tu me reáois?

338
00:17:27,780 --> 00:17:29,840
Surtout, ne le laisse pas s'Çchapper!

339
00:17:31,010 --> 00:17:31,950
Capitaine...

340
00:17:31,950 --> 00:17:33,150
Qu'y a-t-il?

341
00:17:33,150 --> 00:17:35,140
J'aurais besoin de votre coopÇration.

342
00:17:36,950 --> 00:17:40,360
Une attaque Ö bout-pourtant avec les deux cuirassÇs restants?!

343
00:17:40,360 --> 00:17:41,320
Correct.

344
00:17:41,320 --> 00:17:43,430
Nous lui tenderons un piäge en

345
00:17:43,430 --> 00:17:47,230
abandonnant les deux cuirassÇs fraichement evacuÇs
au bout du cable ombilical.

346
00:17:47,230 --> 00:17:50,900
Quand l'EVA ouvrira la gueule de la cible, chacun des navires foncera Ö l'intÇrieur.

347
00:17:50,900 --> 00:17:55,240
Ils tireront simultanÇment avec l'intÇgralitÇ de leurs tourelles,

348
00:17:55,240 --> 00:17:58,640
et enfin s'auto-dÇtruiront, dÇtruisant la cible du màme coup.

349
00:17:58,640 --> 00:18:00,140
C'est grotesque!

350
00:18:00,140 --> 00:18:04,410
Grotesque, peut-àtre. Mais pas impossible..

351
00:18:04,410 --> 00:18:05,410
Entendu.

352
00:18:05,410 --> 00:18:06,610
∑ tout l'Çquipage! Abandonnez le navire!

353
00:18:06,610 --> 00:18:09,350
Je rÇpäte: ∑ tout l'Çquipage! Abandonnez le navire!

354
00:18:12,690 --> 00:18:14,660
mais qu'adviendra-t-il des EVAs?

355
00:18:14,660 --> 00:18:17,190
Ne vous inquiÇtez pas, elles iront bien.

356
00:18:17,190 --> 00:18:21,330
HÇ, ne prends pas les commandes
sans ma permission!

357
00:18:21,330 --> 00:18:23,970
Est-ce que vous comprenez le but de la mission, tous les deux?

358
00:18:23,970 --> 00:18:25,400
Je ferai de mon mieux.

359
00:18:25,400 --> 00:18:26,530
Je compte sur vous.

360
00:18:29,840 --> 00:18:34,040
<i>∑ tous les navires, ouvrez la valve Kingston!</i>
<i>DÇbutez le sabordage au point Z.</i>

361
00:18:34,040 --> 00:18:35,140
Bien reáu!

362
00:18:35,140 --> 00:18:36,300
Rembobinez le cÉble!

363
00:18:44,090 --> 00:18:45,290
<i>L'EVA refait surface!</i>

364
00:18:45,290 --> 00:18:47,050
<i>T-moins 70 avant contact!</i>

365
00:18:48,860 --> 00:18:52,060
HÇ, tu touches Ö mes... dÇgage!

366
00:18:52,060 --> 00:18:55,390
Mais il faut faire en sorte d'ouvrir sa gueule ou sinon on risque de mourir!

367
00:18:59,070 --> 00:19:00,770
<i>T-moins 60 avant contact.</i>

368
00:19:00,770 --> 00:19:02,790
-La gueule, áa avance?
-<i>Toujours pas ouverte!</i>

369
00:19:05,270 --> 00:19:08,340
<i>Les deux cuirassÇs sombrent en direction de la cible</i>

370
00:19:08,340 --> 00:19:10,880
L'EVA continue sa remontÇe.
<i>T-moins 50 avant contact.</i>

371
00:19:10,880 --> 00:19:11,810
Rien n'y fait!

372
00:19:11,810 --> 00:19:12,970
Plus le temps!

373
00:19:19,120 --> 00:19:22,320
<i>La cible vient de passÇ sous</i>
<i>le Tempest!</i>

374
00:19:22,320 --> 00:19:24,290
Faites vite, ou ce sera trop tard!

375
00:19:24,290 --> 00:19:26,130
Ne te fais pas d'idÇes.

376
00:19:26,130 --> 00:19:26,960
Comment áa?

377
00:19:26,960 --> 00:19:29,460
Oublie-áa, essaie juste de te concentrer sur tes pensÇes.

378
00:19:29,460 --> 00:19:30,450
Je sais bien!

379
00:19:35,700 --> 00:19:37,370
<i>T-moins 20 avant contact.</i>

380
00:19:40,140 --> 00:19:42,440
<i>T-moins 15 avant contact.</i>

381
00:19:42,440 --> 00:19:44,580
Ouvre-toi! Ouvre-toi!

382
00:19:44,580 --> 00:19:46,600
Ouvre-toi! Ouvre-toi!

383
00:19:58,260 --> 00:19:59,750
Feu!

384
00:20:16,940 --> 00:20:20,410
<i>Neo-Yokosuka (Vieille-Odawara)</i>

385
00:20:21,850 --> 00:20:23,650
Didiou! C'Çtait franchement spectaculaire!

386
00:20:23,650 --> 00:20:27,220
J'ai dñ improviser. J'aurais dñ envisager un combat sous-marin.

387
00:20:27,220 --> 00:20:29,490
Il est rare de t'entendre parler comme áa.
Serait-ce du regret?

388
00:20:29,490 --> 00:20:32,990
Arràte un peu! On a collectÇ de prÇcieuses donnÇes, en plus.

389
00:20:32,990 --> 00:20:33,980
En effet.

390
00:20:35,000 --> 00:20:37,030
-Misato...
-Hmm?

391
00:20:37,030 --> 00:20:38,520
Ces donnÇes <i>sont</i> prÇcieuses.

392
00:20:45,610 --> 00:20:47,040
Oh... la belle paire!

393
00:20:47,040 --> 00:20:49,180
Haha, Çnorme!

394
00:20:49,180 --> 00:20:51,310
Ils ont explosÇs leurs records de synchro, c'est áa?

395
00:20:51,310 --> 00:20:55,950
Pour seulement sept secondes. Ce devait àtre l'adrÇnaline.

396
00:20:55,950 --> 00:20:57,690
HÇ, oó est passsÇ Kaji?

397
00:20:57,690 --> 00:21:01,550
Il s'est barrÇ. Il doit àtre au QG Ö l'heure qu'il est! Ce pauv' dÇbile!

398
00:21:02,960 --> 00:21:06,630
Eh bien... quel voyage mouvementÇ.

399
00:21:06,630 --> 00:21:08,530
Je me demande si cette chose en est la cause?

400
00:21:13,470 --> 00:21:16,100
Il s'est dÇjÖ complätement restituÇ.

401
00:21:16,100 --> 00:21:19,200
Il est piÇgÇ dans de la dura-bakelite,

402
00:21:19,200 --> 00:21:22,210
mais il est vivant, je n'en ai aucun doute.

403
00:21:22,210 --> 00:21:24,250
C'est la clÇ du <i>Human
Instrumentality Project</i>, c'est áa?

404
00:21:24,250 --> 00:21:25,210
Exacte.

405
00:21:25,210 --> 00:21:27,350
Le premier àtre humain.

406
00:21:27,350 --> 00:21:28,340
Adam.

407
00:21:29,580 --> 00:21:34,160
Elle Çtait p'tet mignonne, mais c'Çtait une vraie pimbàche.

408
00:21:34,160 --> 00:21:37,260
Heureusement, on aura plus Ö voir sa tronche.

409
00:21:37,260 --> 00:21:39,860
Sauf notre bon vieux hÇros qui va la voir tous les jours Ö la base.

410
00:21:39,860 --> 00:21:41,420
Je me sens vraiment dÇsolÇ pour toi.

411
00:21:55,240 --> 00:21:57,780
Je m'appelle Asuka Langley Sohryu.

412
00:21:57,780 --> 00:21:58,470
Ravie de vous rencontrer.

413
00:21:58,500 --> 00:22:00,500
<i>To be continued...</i>

414
00:23:05,900 --> 00:23:06,800
Preview

415
00:23:07,700 --> 00:23:09,900
La premiäre attaque en tandem
des deux EVA...

416
00:23:09,900 --> 00:23:12,000
...mais Shinji et Asuka ne sont pas
synchros.

417
00:23:12,000 --> 00:23:15,700
Misato concocte un plan afin de leur permettre
de travailler Ö l'unisson

418
00:23:15,700 --> 00:23:18,600
Prochain êpisode:
"Momentarily Unite the Minds"

419
00:23:18,600 --> 00:23:22,600
Sans oublier, le fanservice!)";
v=constit(v,s); replique t(s); 
print(v); //cout<<t.compare()<<endl; 
size_t pos(t.debRep(s));
//cout<< s[pos]<<"  jjj "<< s[t.finRep(s,pos)];


	}
