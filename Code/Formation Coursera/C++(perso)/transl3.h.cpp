#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

class timestamp {
	protected:
	vector<string> deb;
	vector<string> fin;

vector<string> debetfin(string, int,size_t);
void impr(vector<string> v);

public:
	string tostring(vector<string>const& s){
		string p(s[0]);
		for (unsigned int i(1); i<s.size()-1; i++)
		{p+=":";
			p+=s[i];}
		return p+=","+s[s.size()-1];
		}
		
vector<string> getDeb() {
	return deb;
	}
vector<string> getFin() {
	return fin;
	}
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
string getRep();
size_t debRep(string);
size_t finRep(string, size_t);	
replique(string) ;
void print();


	
	};
	
	string replique::getRep() {
		return rep;
		}
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
		if (s[pos]=='\n') { //cout<<"*"<<endl;
			ind++;}
		pos++; //cout <<ind;
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
	
	//on arrive … la fin ou au d‚but du timestamp
	//cout<<"pos:"<<pos<<"  "<< "tab:"<<tab<<"   v.size:"<<v.size()<<endl;
	while(pos>=0&&tab>=0&&tab<v.size()) { 
		//cout <<endl<<"while1"<<"   "<<v[tab]<<"  "<<s[pos]<<endl;
		//si ni digit ou app … v, on d‚gage en renvoyant -1;
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
	// j sert … corriger les compteurs pour les TS ‚gaux;
	size_t j(0);
	for (size_t i(0);i<v.size(); i++) {
		if (!v[i].compare()) { 
		cout<<i-j<<endl;
	v[i].print();
} else j++;
}
	}	
void text(vector<replique> v) {
	ofstream file("trad.srt");
	for (unsigned int i(0);i<v.size(); i++) {
	
	file <<i+1<<endl<<v[i].tostring(v[i].getDeb())<<" --> "<<v[i].tostring(v[i].getFin())<<endl<<v[i].getRep()<<endl<<endl;

}
	
	file.close();
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
00:01:30,500 --> 00:01:33,100
2015 ap. J.-C.

22
00:01:55,049 --> 00:01:59,086
<i>Depuis 01:12:30, cette après-midi,</i>
<i>un état d'urgence a été spécialement déclaré</i>

23
00:01:59,086 --> 00:02:03,216
<i>pour les régions du Kanto et du Chubut</i>
<i>aux alentours de la sous-région de Tokai.</i>

24
00:02:03,724 --> 00:02:07,751
<i>Nous demandons aux habitants de rejoindre </i>
<i>leurs abris respectifs immédiatement.</i>

25
00:02:08,196 --> 00:02:12,533
<i>Je répète : depuis 01:12:30, cette après-midi,</i>

26
00:02:12,533 --> 00:02:16,204
<i>les régions du Kanto et du Chubut</i>
<i>aux alentours de la sous-région de Tokai.</i>

27
00:02:16,204 --> 00:02:19,340
<i>sont officiellement déclarées</i>
<i>en état d'urgence.</i>

28
00:02:19,340 --> 00:02:21,075
<i>Nous demandons aux habitants de rejoindre </i>
<i>leurs abris respectifs immédiatement.</i>

29
00:02:21,100 --> 00:02:24,235
Bon Dieu, fallait vraiment que je perde sa trace ?

30
00:02:24,462 --> 00:02:26,273
C'est pas le moment...

31
00:02:27,482 --> 00:02:29,984
<i>Du fait de cette urgence singulière</i>

32
00:02:29,984 --> 00:02:33,249
<i>toutes les lignes sont momentanément indisponibles.</i>

33
00:02:34,689 --> 00:02:35,678
Rien à faire.

34
00:02:36,724 --> 00:02:39,022
Je n'aurais pas dû venir.

35
00:02:42,900 --> 00:02:43,400
<i>[Regarde par ici!!]</i>
<i> </i>

36
00:02:43,400 --> 00:02:45,700
<i>[Regarde par ici!!]</i>
J'imagine que je la rencontrerai une autre fois...

37
00:02:46,834 --> 00:02:49,428
Pour l'instant, contentons-nous du refuge.

38
00:03:15,096 --> 00:03:18,554
L'objet non identifié se dirige droit en direction du QG.

39
00:03:19,333 --> 00:03:22,564
On a un visuel direct sur lui. Il va apparaître sur l'écran principal.

40
00:03:24,238 --> 00:03:26,140
Cela fait bien 15 ans, maintenant.

41
00:03:26,140 --> 00:03:28,267
Oui.
Désormais, plus aucun doute.

42
00:03:29,243 --> 00:03:30,540
Les Anges sont là.

43
00:03:30,700 --> 00:03:33,300
EPISODE 1:
ANGEL ATTACK

44
00:03:42,623 --> 00:03:44,284
Torpillez la cible à volonté!

45
00:04:03,477 --> 00:04:05,069
Désolée! 'Pas trop attendu ?

46
00:04:22,496 --> 00:04:26,734
La cible est toujours opérationnelle.
Elle continue sa course vers Tokyo-3.

47
00:04:26,734 --> 00:04:29,259
La Force Aérienne de Défense manque de puissance de feu pour l'arrêter!

48
00:04:30,071 --> 00:04:31,405
Balancez-tout !

49
00:04:31,405 --> 00:04:33,274
Mobilisez tous les gars d'Atsugi
et d'Iruma!

50
00:04:33,274 --> 00:04:36,675
Oubliez ce foutu budget!
Détruisez la cible à tout prix!

51
00:04:49,657 --> 00:04:51,955
Que diable?! L'attaque était frontale!

52
00:04:52,760 --> 00:04:55,062
Le bataillon de tank a été anéanti.

53
00:04:55,062 --> 00:04:58,165
Les missiles auto-guidés et l'artillerie
n'ont eu aucun effet non plus.

54
00:04:58,165 --> 00:05:01,569
C'est pas vrai ! On a utilisé toutes nos forces
et on ne l'a même pas égratiné !

55
00:05:01,569 --> 00:05:03,504
Il est protégé par un AT-Field, n'est-ce pas ?

56
00:05:03,504 --> 00:05:07,304
Oui. Les armes conventionnelles ne peuvent rien contre les Anges.

57
00:05:10,878 --> 00:05:13,938
C'est entendu, mon général. Le plan
sera executé à l'instant.

58
00:05:18,753 --> 00:05:20,321
Hé, me dites pas que...

59
00:05:20,321 --> 00:05:22,186
Ils s'apprètent à lacher une bombe N2?!

60
00:05:22,690 --> 00:05:24,157
Couche-toi!

61
00:05:46,881 --> 00:05:48,348
On a réussi!

62
00:05:48,749 --> 00:05:51,919
Désolé, mais on dirait que vous allez devoir
passer votre tour.

63
00:05:51,919 --> 00:05:54,114
Onde de choc, en approche.

64
00:05:55,222 --> 00:05:56,723
Tout va bien de ton côté?

65
00:05:56,723 --> 00:05:56,824
Oui, mais ma bouche est pleine de terre.

66
00:05:56,824 --> 00:06:00,194
Oui, mais ma bouche est pleine de terre.

67
00:06:00,194 --> 00:06:04,028
C'est pas bien grave.
Bon, on s'y met !

68
00:06:04,699 --> 00:06:06,166
Et... Pousse !

69
00:06:10,204 --> 00:06:11,671
Voilà..

70
00:06:14,742 --> 00:06:16,911
Merci du coup de main,
Je t'en suis reconnaissante.

71
00:06:16,911 --> 00:06:19,980
Merci à vous aussi, Madame Katsuragi.

72
00:06:19,980 --> 00:06:22,039
C'est Misato, je t'en prie.

73
00:06:22,516 --> 00:06:26,153
Heureuse d'enfin te rencontrer,
Ikari Shinji.

74
00:06:26,153 --> 00:06:27,142
Oui...

75
00:06:27,521 --> 00:06:28,856
État de la cible ?

76
00:06:28,856 --> 00:06:31,826
Impossible de le vérifier, les EMPs
brouillent les capteurs.

77
00:06:31,826 --> 00:06:34,662
Il ne doit rien en rester.
Vous avez vu la taille de l'explosion.

78
00:06:34,662 --> 00:06:36,129
Capteurs restaurés.

79
00:06:37,398 --> 00:06:39,100
Nous relevons une signature énergétique à
l'épicentre.

80
00:06:39,300 --> 00:06:40,501
PARDON?!

81
00:06:40,501 --> 00:06:40,801
Affichage visuel restauré.

82
00:06:40,801 --> 00:06:42,132
Affichage visuel restauré.

83
00:06:46,407 --> 00:06:48,637
C'était notre dernière carte.

84
00:06:49,577 --> 00:06:51,272
Bonté divine...

85
00:06:51,645 --> 00:06:53,112
C'est un véritable démon !

86
00:07:03,057 --> 00:07:05,526
Oui. Ne vous en faites pas.

87
00:07:05,526 --> 00:07:07,966
Sa sécurité est ma première priorité,

88
00:07:08,000 --> 00:07:11,130
Apprêtez une nacelle pour notre arrivée, ok?
La plus rapide.

89
00:07:15,436 --> 00:07:18,732
c'est donc ma responsabilité de le voir arriver sain et sauf. A bientôt!

90
00:07:20,500 --> 00:07:27,300
<i>Oh, ça craint ! Je viens de faire réparer cette caisse, et c'est déjà une épave.</i>

91
00:07:27,300 --> 00:07:33,300
<i>J'en suis déjà à 33 crédits...</i>
<i>plus les coûts pour la réparer....</i>

92
00:07:33,300 --> 00:07:34,200
Hmm, Misato....
<i>J'en suis déjà à 33 crédits...</i>
<i>plus les coûts pour la réparer....</i>

93
00:07:34,200 --> 00:07:37,500
Hmm, Misato....
<i>Pire, mes seuls vêtements potables...</i>
<i>des chiffons....</i>

94
00:07:37,725 --> 00:07:39,126
Excusez-moi, Misato?

95
00:07:39,126 --> 00:07:39,226
Excusez-moi, Misato?

96
00:07:39,226 --> 00:07:40,694
Q- Quoi?

97
00:07:40,694 --> 00:07:43,424
Vous êtes sûre que vous avez droit de vous servir?

98
00:07:45,199 --> 00:07:46,233
T'occupe pas de ça!

99
00:07:46,233 --> 00:07:50,070
C'est un cas d'urgence, et il nous faut une voiture en état de marche, non?

100
00:07:50,070 --> 00:07:53,641
et après tout, je suis un agent officiel du gouvernement.

101
00:07:53,641 --> 00:07:56,133
<i>"Ce qui est pris n'est plus à prendre"</i>!

102
00:07:56,610 --> 00:07:59,313
Je ne crois pas que quiconque tombera dans le panneau.

103
00:07:59,313 --> 00:08:03,409
C'est pas le moment d'être casse-pied.
T'es pas aussi mignon que j'imaginais.

104
00:08:04,351 --> 00:08:05,753
Vous trouvez..?

105
00:08:05,753 --> 00:08:05,853
Oh, je t'ai blessé ?

106
00:08:05,853 --> 00:08:07,480
Oh, je t'ai blessé ?

107
00:08:08,422 --> 00:08:11,692
Désolée, vraiment. J'ai oublié que tu
n'étais qu'un enfant, après tout.

108
00:08:11,692 --> 00:08:14,991
C'est plutôt vous, Misato, qui n'êtes pas aussi mature que j'imaginais.

109
00:08:20,701 --> 00:08:23,938
Comme nous l'avions envisagé, ils sont capables de se régénerer.

110
00:08:23,938 --> 00:08:27,806
Autrement, ils ne mériteraient pas leur surnom d'armes autonomes polyvalentes.

111
00:08:30,311 --> 00:08:35,010
Impressionant. On dirait qu'il est même capable d'améliorer ses fonctions en plein combat.

112
00:08:35,382 --> 00:08:37,646
Et il semble être capable d'apprendre.

113
00:08:38,686 --> 00:08:41,587
Il va reprendre son chemin
d'un instant à l'autre.

114
00:08:42,990 --> 00:08:46,560
<i> </i>
<i>Fermeture du portail. Prière de dégager le passage.</i>

115
00:08:46,560 --> 00:08:48,095
Agence spéciale - Nerv?
<i>Fermeture du portail. Prière de dégager le passage.</i>

116
00:08:48,095 --> 00:08:48,362
Oui, c'est une organisation secrète, sous contrôle des Nations Unies.
<i>Fermeture du portail. Prière de dégager le passage.</i>

117
00:08:48,362 --> 00:08:48,529
Oui, c'est une organisation secrète, sous contrôle des Nations Unies.
<i> </i>

118
00:08:48,529 --> 00:08:52,100
Oui, c'est une organisation secrète, sous contrôle des Nations Unies.
<i>Vous êtes dans le train B22 Special Express, en direction du G33</i>

119
00:08:52,100 --> 00:08:53,600
C'est celle dont mon père fait partie, non ?
<i>Vous êtes dans le train B22 Special Express, en direction du G33</i>

120
00:08:53,600 --> 00:08:56,829
Eh, oui... tu sais ce que ton père y fabrique ?
<i>Vous êtes dans le train B22 Special Express, en direction du G33</i>

121
00:08:58,038 --> 00:09:00,750
<i> </i>
<i>Cette ligne directe ignorera tous les autres arrêts</i>

122
00:09:00,750 --> 00:09:04,777
Mes professeurs m'ont dit que ça avait à voir avec la sauvegarde de l'Humanité.

123
00:09:07,615 --> 00:09:10,851
À cet instant, les rennes de cette opération vous sont livrés.

124
00:09:10,851 --> 00:09:12,553
Montrez-nous de quoi vous êtes capable.

125
00:09:12,553 --> 00:09:13,721
Entendu.

126
00:09:13,721 --> 00:09:14,054
M. Ikari, nous n'avons d'autres choix que d'admettre l'inefficacité de nos méthodes contre l'ennemi.

127
00:09:14,054 --> 00:09:19,788
M. Ikari, nous n'avons d'autres choix que d'admettre l'inefficacité de nos méthodes contre l'ennemi.

128
00:09:21,228 --> 00:09:23,828
Êtes-vous vraiment sûr de pouvoir battre ces choses?

129
00:09:24,198 --> 00:09:26,189
C'est ce pourquoi la NERV a été crée.

130
00:09:26,600 --> 00:09:28,090
Prions pour que vous ayez raison.

131
00:09:29,737 --> 00:09:31,939
<i>La cible est encore stationnaire.</i>

132
00:09:31,939 --> 00:09:35,306
<i>Notre capacité d'interception est seulement de 7.5%.</i>

133
00:09:36,977 --> 00:09:39,380
Même les forces des N.U. sont épuisées.

134
00:09:39,380 --> 00:09:40,972
Que comptes-tu faire?

135
00:09:41,482 --> 00:09:43,473
J'ai l'intention d'activer l'UNITÉ-01.

136
00:09:43,717 --> 00:09:46,811
L'UNITÉ-01? Mais nous n'avons pas de pilote.

137
00:09:47,454 --> 00:09:51,049
Aucun problème. Une rechange va nous être apporté très bientôt.

138
00:09:52,026 --> 00:09:54,756
Vous m'emmenez voir mon père ?

139
00:09:55,262 --> 00:09:57,355
Oui. Il me semble, oui.

140
00:10:01,201 --> 00:10:02,668
Père...

141
00:10:04,038 --> 00:10:07,405
Ah, au fait.
Ton père ne t'as pas fait parvenir ton pass ?

142
00:10:09,310 --> 00:10:10,777
Si.

143
00:10:11,979 --> 00:10:13,080
Le voilà.

144
00:10:13,080 --> 00:10:13,980
<i> </i>
Merci.

145
00:10:13,980 --> 00:10:15,138
<i>[Note: Viens ici!]</i>
Merci.

146
00:10:15,916 --> 00:10:18,384
Bien... maintenant,
lis-moi ça.

147
00:10:18,886 --> 00:10:20,421
NERV...

148
00:10:20,421 --> 00:10:22,218
L'agence de mon père...

149
00:10:22,957 --> 00:10:25,016
Est-ce que je vais devoir travailler pour lui ?

150
00:10:26,961 --> 00:10:28,529
Quelle question...

151
00:10:28,529 --> 00:10:32,761
Il ne m'aurait envoyé de lettre que s'il avait vraiment besoin de moi.

152
00:10:33,167 --> 00:10:36,693
Je vois... vous n'avez pas l'air de vraiment vous entendre, toi et ton père.

153
00:10:37,604 --> 00:10:39,196
C'est pareil avec le mien.

154
00:10:45,179 --> 00:10:46,646
Incroyable!

155
00:10:47,748 --> 00:10:49,416
C'est un Géo-Front, un vrai !

156
00:10:49,416 --> 00:10:54,088
En effet ! Tu es dans notre base secrète:
le QG de la NERV.

157
00:10:54,088 --> 00:10:55,823
Voilà la clé pour la reconstruction,

158
00:10:55,823 --> 00:10:58,291
la forteresse qui protègera l'Humanité.

159
00:10:59,700 --> 00:11:01,300
NEON GENESIS
EVANGELION

160
00:11:05,465 --> 00:11:07,742
Nom de non...

161
00:11:07,742 --> 00:11:09,950
C'est toujours pas le bon chemin ?

162
00:11:10,570 --> 00:11:12,506
<i>Les couloirs hermétiques du Central Dogma demeurent scellés.</i>

163
00:11:12,506 --> 00:11:15,275
Voilà pourquoi je déteste porter des jupes au boulot.
<i>Les couloirs hermétiques du Central Dogma demeurent scellés.</i>

164
00:11:15,375 --> 00:11:16,043
<i>Ouverture séquencée du Block B-26 .</i>

165
00:11:16,043 --> 00:11:18,011
Bon sang, ou est passée Ritsuko ?
<i>Ouverture séquencée du Block B-26 .</i>

166
00:11:18,011 --> 00:11:18,879
Bon sang, ou est passée Ritsuko ?
<i>  </i>

167
00:11:18,879 --> 00:11:21,508
Désolée, je suis pas encore habituée à cet endroit.

168
00:11:21,508 --> 00:11:23,739
On est déjà passé par là tout à l'heure.

169
00:11:25,118 --> 00:11:26,620
Mais ne t'inquiète pas !

170
00:11:26,620 --> 00:11:29,122
Si ces sytèmes existent, c'est bien pour être utilisés !

171
00:11:29,122 --> 00:11:31,725
<i>Nous prions la présidente du E-project,</i>
<i>Département Technique, Division 1,</i>

172
00:11:31,725 --> 00:11:34,861
<i>Dr. Ritsuko Akagi,</i>
<i>Dr. Ritsuko Akagi,</i>

173
00:11:34,861 --> 00:11:39,866
<i>de bien vouloir contacter le capitaine Misato Katsuragi, du Département des Operations, Division 1, et ce immédiatement.</i>

174
00:11:39,866 --> 00:11:42,964
Je n'y crois pas.
 Elle a encore réussi à se perdre?

175
00:11:47,140 --> 00:11:49,199
...Salut, Ritsuko.

176
00:11:53,880 --> 00:11:56,350
Pourquoi me faites-<i>vous</i> perdre mon temps, Capitaine Katsuragi?

177
00:11:56,350 --> 00:11:57,850
<i>Vous</i> n'ignorez pas que nous sommes

178
00:11:57,850 --> 00:12:00,553
-à court de temps ET de personnel?
-Pardon !

179
00:12:03,390 --> 00:12:05,292
Voilà le fameux garçon ?

180
00:12:05,292 --> 00:12:09,228
C'est ça. Selon le rapport Marduk, c'est le Pupille Troisième.

181
00:12:09,930 --> 00:12:11,098
Ravie de te rencontrer.

182
00:12:11,098 --> 00:12:11,431
Ravie de te rencontrer.

183
00:12:11,831 --> 00:12:12,999
hmmoui.

184
00:12:12,999 --> 00:12:17,732
C'est le portrait de son père, celui-là.
La partie revêche, bien sûr.

185
00:12:18,105 --> 00:12:19,766
Occupe-toi du reste pour moi.

186
00:12:24,211 --> 00:12:26,441
Leur première rencontre après trois longues années.

187
00:12:27,481 --> 00:12:31,218
Vice-Commandant, la cible s'est remise en mouvement.

188
00:12:31,218 --> 00:12:34,788
Bien. Entrez en posture de combat de niveau 1.

189
00:12:34,788 --> 00:12:39,526
<i>Je répète. Posture de combat, Niveau 1.</i>
<i>Soyez prêts pour une intervention au sol.</i>

190
00:12:39,526 --> 00:12:40,827
Nous y voilà.

191
00:12:40,827 --> 00:12:41,027
Les choses ont l'air sérieuses.

192
00:12:41,027 --> 00:12:42,358
Les choses ont l'air sérieuses.

193
00:12:43,163 --> 00:12:45,399
Sinon, du progrès sur l'UNITÉ-01 ?

194
00:12:45,399 --> 00:12:47,801
En plein procédé de réfrigération,
avec l'équipement de type-B.

195
00:12:47,801 --> 00:12:51,738
Est-ce qu'elle fonctionne vraiment ?
 A-t-elle jamais fonctionnée, à-vrai-dire ?

196
00:12:51,738 --> 00:12:56,835
Les chances de réactivation sont de 0.000000001%.

197
00:12:57,244 --> 00:12:59,813
On l'appelle le O-9 System,
aussi pathétique que ça sonne.

198
00:12:59,813 --> 00:13:02,449
Ca veut dire qu'elle ne marche jamais ?

199
00:13:02,449 --> 00:13:03,785
Oh, ne sois pas vulgaire.

200
00:13:03,785 --> 00:13:07,154
-C'est un "O", pas un zéro.
-Oh, c'est juste un nombre.

201
00:13:07,154 --> 00:13:11,284
Peu importe au final. Il est un peu tard
pour les excuses.

202
00:13:20,300 --> 00:13:23,064
Uh- Que- il fait tout noir d'un coup!

203
00:13:26,640 --> 00:13:29,404
Une tête ? Un robot géant ?

204
00:13:31,111 --> 00:13:33,272
Tu ne risques pas de le trouver
dans ton manuel.

205
00:13:33,847 --> 00:13:37,818
Voilà l'invention, la machine humanoide de guerre ultime,

206
00:13:37,818 --> 00:13:42,020
le premier modèle de la forme de vie synthétique qu'on nomme l'Evangelion:
L'UNITÉ 01.

207
00:13:42,020 --> 00:13:47,260
Conçue dans le secret, elle est le dernier espoir de l'Humanité.

208
00:13:47,260 --> 00:13:49,129
Est-ce que mon père a à voir avec tout ça ?

209
00:13:49,129 --> 00:13:50,596
Correct.

210
00:13:52,098 --> 00:13:53,725
Ça fait longtemps.

211
00:13:54,801 --> 00:13:56,268
Père...

212
00:13:58,738 --> 00:13:59,840
On décroche.

213
00:13:59,840 --> 00:14:00,240
Une mise-en-route?! Avec l'UNITÉ-00 encore en cryo-stase?

214
00:14:00,240 --> 00:14:03,641
Une mise-en-route?! Avec l'UNITÉ-00 encore en cryo-stase?

215
00:14:05,178 --> 00:14:08,181
Attendez une minute. Vous voulez utiliser l'UNITÉ-01 ?

216
00:14:08,181 --> 00:14:09,749
Il n'y a pas d'autre moyen.

217
00:14:09,749 --> 00:14:12,809
Mais attendez, Rei est toujours incapacitée, n'est-ce pas ?

218
00:14:13,487 --> 00:14:15,284
Nous avons aucun pilote !

219
00:14:15,889 --> 00:14:17,550
Un vient juste d'arriver.

220
00:14:18,391 --> 00:14:19,858
Pardon ?

221
00:14:20,260 --> 00:14:21,461
Ikari Shinji...

222
00:14:21,461 --> 00:14:21,761
Ikari Shinji...

223
00:14:21,761 --> 00:14:22,596
Oui?

224
00:14:22,596 --> 00:14:22,963
Tu seras notre pilote.

225
00:14:22,963 --> 00:14:24,055
Tu seras notre pilote.

226
00:14:24,698 --> 00:14:29,870
Mais enfin, même à Ayanami Rei, il a fallut 7 mois avant de parvenir à se synchroniser.

227
00:14:29,870 --> 00:14:32,572
Il n'a aucune chance d'y arriver,
Il vient d'arriver !

228
00:14:32,572 --> 00:14:35,442
Il a juste à s'asseoir dans le cockpit.
Nous ne lui demandons rien d'autre.

229
00:14:35,442 --> 00:14:36,510
Mais enfin...

230
00:14:36,510 --> 00:14:36,943
Repousser l'Ange est notre priorité absolue.

231
00:14:36,943 --> 00:14:39,173
Repousser l'Ange est notre priorité absolue.

232
00:14:39,679 --> 00:14:42,550
Si mettre un individu capable de se synchroniser avec l'EVA

233
00:14:42,550 --> 00:14:45,675
nous offre la moindre chance de gagner,
alors nous la prendrons.

234
00:14:46,419 --> 00:14:48,819
Vous comprenez la teneur des enjeux,
Capitaine Katsuragi ?

235
00:14:50,924 --> 00:14:52,391
Je suppose.

236
00:14:54,160 --> 00:14:56,429
Père, pourquoi m'as-tu fais venir ?

237
00:14:56,429 --> 00:14:58,798
Tu sais très bien pourquoi.

238
00:14:58,798 --> 00:15:02,859
Tu me demandes de m'installer dans ce machin et d'aller me battre ?

239
00:15:03,236 --> 00:15:04,204
Précisemment.

240
00:15:04,204 --> 00:15:04,738
Pas question ! Comment peux-tu me demander une chose pareille!

241
00:15:04,738 --> 00:15:07,707
Pas question ! Comment peux-tu me demander une chose pareille!

242
00:15:07,707 --> 00:15:10,477
Je pensais que je ne t'intéressais plus !

243
00:15:10,477 --> 00:15:12,870
Tu es là car j'ai besoin de toi
en ce moment-même.

244
00:15:15,315 --> 00:15:16,873
Pourquoi moi ?

245
00:15:17,350 --> 00:15:19,750
Car personne d'autre ne le peut.

246
00:15:20,420 --> 00:15:22,589
Je ne pourrai jamais...

247
00:15:22,589 --> 00:15:26,286
Je n'ai jamais entendu parlé de ce truc. Comment peux-tu penser que j'y arriverai?!!

248
00:15:26,960 --> 00:15:28,552
Tu recevras des instructions.

249
00:15:29,029 --> 00:15:31,200
Mais c'est...

250
00:15:31,370 --> 00:15:32,992
...impossible !

251
00:15:33,600 --> 00:15:35,830
Je peux pas le piloter !

252
00:15:36,870 --> 00:15:38,991
Si tu comptes piloter, alors rentre dedans et vite.

253
00:15:39,070 --> 00:15:42,971
Sinon, du balai !

254
00:15:51,885 --> 00:15:54,513
Il doit avoir repéré notre position.

255
00:15:57,958 --> 00:16:00,188
Shinji, le temps nous manque.

256
00:16:04,931 --> 00:16:06,398
Rentre à l'intérieur.

257
00:16:07,233 --> 00:16:11,966
Non ! J'ai fait tout ce chemin pour ça???
Ça n'a aucun sens!

258
00:16:13,106 --> 00:16:16,405
Shinji,  pourquoi es-tu venu au juste ?

259
00:16:18,311 --> 00:16:22,771
Tu dois faire face à ton père... et aussi à toi-même.

260
00:16:23,283 --> 00:16:27,049
Je sais ! Mais... je n'y arrive pas !

261
00:16:35,395 --> 00:16:36,862
Fuyutsuki...

262
00:16:37,631 --> 00:16:39,199
Réveille Rei.

263
00:16:39,199 --> 00:16:40,500
On pourra se servir d'elle ?

264
00:16:40,500 --> 00:16:40,700
On pourra se servir d'elle ?

265
00:16:40,700 --> 00:16:42,429
Elle n'est pas encore morte, si ?

266
00:16:43,303 --> 00:16:44,770
Entendu.

267
00:16:46,239 --> 00:16:47,050
Rei...

268
00:16:47,150 --> 00:16:47,831
Oui?

269
00:16:47,741 --> 00:16:48,174



270
00:16:48,174 --> 00:16:48,541
Ta rechange se trouve être inutile.
Je vais devoir compter sur toi.

271
00:16:48,541 --> 00:16:51,044
Ta rechange se trouve être inutile.
Je vais devoir compter sur toi.

272
00:16:51,044 --> 00:16:51,724
Ok.

273
00:16:54,347 --> 00:16:57,884
Reconfigurez le système de l'UNITÉ-01 pour rei, puis réactivez-la!

274
00:16:57,884 --> 00:16:58,684
Bien reçu.

275
00:16:58,684 --> 00:17:01,445
Annulation de l'instance actuel, et lancement de la procédure de réactivation.

276
00:17:02,822 --> 00:17:06,622
Je m'en doutais. Ils n'avaient pas vraiment besoin de moi.

277
00:17:40,760 --> 00:17:42,227
Attention!

278
00:17:51,504 --> 00:17:52,906
<i>L'eva a bougé!</i>

279
00:17:52,906 --> 00:17:53,006
<i>Comment a-t-elle pu?</i>

280
00:17:53,006 --> 00:17:53,973
<i>Comment a-t-elle pu?</i>

281
00:17:53,973 --> 00:17:54,407
<i>Elle a explosé les attaches du bras droit!</i>

282
00:17:54,407 --> 00:17:56,513
<i>Elle a explosé les attaches du bras droit!</i>

283
00:17:56,533 --> 00:17:58,678
Non, c'est inconcevable!

284
00:17:58,678 --> 00:18:00,880
L'entry plug n'était pas insérée !

285
00:18:00,880 --> 00:18:02,347
Ce n'est pas possible!

286
00:18:03,016 --> 00:18:06,086
Pas d'interface, et pourtant elle a bougé!

287
00:18:06,086 --> 00:18:08,154
ou plutôt... elle l'a protégé?

288
00:18:08,154 --> 00:18:09,621
Elle l'a protégé lui ?

289
00:18:10,623 --> 00:18:12,090
On peut le faire.

290
00:18:32,245 --> 00:18:34,823
Arrête de fuir! Arrête de fuir!

291
00:18:34,863 --> 00:18:36,783
Arrête de fuir! Arrête de fuir!

292
00:18:36,783 --> 00:18:38,250
ARRÊTE DE FUIR !

293
00:18:40,019 --> 00:18:42,852
Laissez-moi le faire. Laissez-moi piloter.

294
00:18:46,025 --> 00:18:47,393
<i>Processus de refroidissment, terminé.</i>

295
00:18:47,393 --> 00:18:47,527
<i>Réparations du bras droit, terminée.</i>

296
00:18:47,527 --> 00:18:48,900
<i>Réparations du bras droit, terminée.</i>

297
00:18:48,900 --> 00:18:51,898
<i>Cage alignée et prête au chargement. </i>

298
00:18:51,898 --> 00:18:54,731
Codon-stop de la signal plug, ejecté.

299
00:18:55,435 --> 00:18:57,960
<i>Bien reçu. </i>
<i>Démarrons l'insertion de l'entry plug.</i>

300
00:19:05,011 --> 00:19:06,579
<i>Capsule fixée.</i>

301
00:19:06,579 --> 00:19:08,240
<i>Procédure de premier contact, enclenchée.</i>

302
00:19:13,119 --> 00:19:15,246
<i>Remplissage de l'entry plug.</i>

303
00:19:16,022 --> 00:19:17,717
Qu'est-ce que c'est que ce truc?

304
00:19:21,461 --> 00:19:24,531
Ne t'inquiète pas. Une fois que le LCL aura empli tes poumons,

305
00:19:24,531 --> 00:19:27,056
il irriguera directement ton sang en oxygène.

306
00:19:27,433 --> 00:19:29,025
Tu t'y feras très vite.

307
00:19:32,071 --> 00:19:33,506
Ça me donne la nausée...

308
00:19:33,506 --> 00:19:35,940
Arrête de pleurnicher !
Tu es un garçon, oui ou non ?!

309
00:19:37,110 --> 00:19:38,278
<i>Connection à la source d'alimentation principal.</i>

310
00:19:38,278 --> 00:19:39,012
<i>L'ensemble des circuits est maintenant mobilisé.</i>

311
00:19:39,012 --> 00:19:40,680
<i>L'ensemble des circuits est maintenant mobilisé.</i>

312
00:19:40,900 --> 00:19:41,800
<i>Bien reçu.</i>

313
00:19:41,800 --> 00:19:44,045
<i>Procédure de second contact, enclenchée.</i>

314
00:19:45,151 --> 00:19:47,847
<i>Connection au nerf A-10, valeurs normales.</i>

315
00:19:49,523 --> 00:19:53,359
<i>Configuration de la logique langagière</i>
<i>-Interface japonaise.</i>

316
00:19:53,359 --> 00:19:55,929
<i>Tous les contacts préliminaires ont été établis.</i>
<i>Performance, nominale.</i>

317
00:19:55,929 --> 00:19:58,131
<i>Circuits bi-directionnels, ouverts.</i>

318
00:19:58,131 --> 00:20:00,829
Taux de synchronisation à 41.3%

319
00:20:01,467 --> 00:20:02,669
Incroyable.

320
00:20:02,669 --> 00:20:02,969
Les harmoniques ont des valeurs normales.
Aucune perturbation identifiée.

321
00:20:02,969 --> 00:20:06,405
Les harmoniques ont des valeurs normales.
Aucune perturbation identifiée.

322
00:20:06,940 --> 00:20:08,407
On peut le faire.

323
00:20:09,342 --> 00:20:10,900
Paré au lancement !

324
00:20:12,444 --> 00:20:13,534
<i>Paré au lancement !</i>

325
00:20:13,813 --> 00:20:15,776
<i>Désamorcez les verrous principaux.</i>

326
00:20:17,217 --> 00:20:20,953
<i>Désarmorçage confirmé. Détachez le pont ombilicale.</i>

327
00:20:22,789 --> 00:20:24,279
<i>Désamorcez les verrous secondaires.</i>

328
00:20:26,593 --> 00:20:28,561
<i>Désengagez les attaches primaires.</i>

329
00:20:28,561 --> 00:20:31,457
<i>Désengagez  les attaches secondaires.</i>

330
00:20:34,358 --> 00:20:38,337
<i>Ouvrez les verrou de sécurité,</i>
<i> liste: 1 à 15.</i>

331
00:20:38,673 --> 00:20:40,541
<i>Batteries internes, pleines.</i>

332
00:20:40,741 --> 00:20:43,771
<i>Connectique de la batterie externe, R.A.S.</i>

333
00:20:45,078 --> 00:20:48,047
Bien reçu. Transportez l'EVA-01 sur le module d'éjection.

334
00:21:03,530 --> 00:21:05,610
Rampe de lancement, dégagée.
Tous les voyants sont au vert.

335
00:21:05,759 --> 00:21:08,101
Tout est prêt pour le lancement.

336
00:21:08,301 --> 00:21:10,003
Bien reçu.

337
00:21:10,003 --> 00:21:11,237
Pouvons-nous commencer?

338
00:21:11,237 --> 00:21:11,504
Pouvons-nous commencer?

339
00:21:11,504 --> 00:21:12,698
Bien sûr.

340
00:21:13,039 --> 00:21:15,974
Si les Anges parviennent à leur fin, aucun avenir n'est possible.

341
00:21:17,210 --> 00:21:20,202
Ikari, es-tu sûr de ton coup?

342
00:21:21,881 --> 00:21:23,348
Départ !

343
00:21:56,749 --> 00:21:58,800
Shinji, essaie de nous revenir vivant.

344
00:21:58,800 --> 00:22:00,300
TO BE CONTINUED

345
00:23:05,700 --> 00:23:06,800
Preview

346
00:23:07,000 --> 00:23:10,000
L'EVA a battu l'Ange,
mais ce n'est que le début.

347
00:23:10,500 --> 00:23:13,600
Shinji s'en va loin de son père
et insiste pour rester seul...

348
00:23:13,700 --> 00:23:16,100
...mais Misato intervient pour le soutenir.

349
00:23:16,100 --> 00:23:20,800
Prochain Épisode: "Unknown Ceilings"
Et pas de soucis, nous n'oublions pas le fan-service!)";
v=constit(v,s); replique t(s); 
text(v);
print(v); //cout<<t.compare()<<endl; 
size_t pos(t.debRep(s));
//cout<< s[pos]<<"  jjj "<< s[t.finRep(s,pos)];


	}
