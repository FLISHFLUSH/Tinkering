
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* class String: public string {
	public:
	String (string str): string(str) {}
	
	
	 String tolower(){
		 string s(*this);
		 for (unsigned int i(0); i<s.length(); i++)
		 s[i]=std::tolower(s[i]);
		return String(s);
		}
		
	/* int compare_NC(string s) {
		string s1(this->tolower());
		return s1.compare(*this);
		}

	};*/

int main() {
	const char * s=R"(1
00:00:01,300 --> 00:00:07,200
<i>Zankoku na tenshi no youni</i>
Like an angel without a sense of mercy...

2
00:00:07,200 --> 00:00:14,600
<i>Shonen yo shinwa ni nare</i>
...rise young boy to the heavens as a legend.

3
00:00:18,700 --> 00:00:22,200
Neon Genesis
Evangelion

4
00:00:22,800 --> 00:00:25,900
<i>Aoi kaze ga ima</i>
Cold winds, as blue as the sea...

5
00:00:25,900 --> 00:00:29,600
<i>Mune no door wo tataitemo</i>
Tear open the door to your heart...

6
00:00:29,600 --> 00:00:33,400
<i>Watashidake wo tada mitsumete</i>
But unknowing you seem, just staring at me...

7
00:00:33,400 --> 00:00:37,700
<i>Hohoenderu anata</i>
Standing there smiling serenely.

8
00:00:37,700 --> 00:00:40,900
<i>Sotto fureru mono</i>
Desperate for something to touch...

9
00:00:40,900 --> 00:00:44,700
<i>Motomeru koto ni muchu de</i>
A moment of kindness like that in a dream..

10
00:00:44,700 --> 00:00:48,100
<i>Unmei sae mada shiranai</i>
Your innocent eyes as yet have no idea...

11
00:00:48,100 --> 00:00:51,300
<i>Itaikena hitomi</i>
...of the path your destiny will follow.

12
00:00:52,300 --> 00:00:55,800
<i>Dakedo itsuka kizuku deshou</i>
But someday you'll become aware of...

13
00:00:55,800 --> 00:00:58,600
<i>Sono senaka niwa</i>
...everything that you've got behind you.

14
00:00:59,600 --> 00:01:03,500
<i>Haruka mirai mezasu tameno</i>
Your wings are for seeking out...

15
00:01:03,500 --> 00:01:06,800
<i>Hanega arukoto</i>
...a new future that only you can search for.

16
00:01:07,100 --> 00:01:10,800
<i>Zankoku na tenshi no thesis</i>
The cruel angel's thesis bleeds...

17
00:01:10,800 --> 00:01:14,600
<i>Madobe kara yagate tobitatsu</i>
...through a portal like your pulsing blood.

18
00:01:14,600 --> 00:01:18,300
<i>Hotobashiru atsui pathos de</i>
If you should betray the chapel of your memories...

19
00:01:18,300 --> 00:01:22,100
<i>Omoide wo uragiru nara</i>
...the cruel angel will enter the window of your soul.

20
00:01:22,100 --> 00:01:25,800
<i>Kono sora wo daite kagayaku.</i>
So boy, stand tall and embrace the fire of legend...

21
00:01:25,800 --> 00:01:30,200
<i>Shonen yo shinwa ni nare.</i>
Embrace the universe like a blazing star!

22
00:01:33,000 --> 00:01:35,050
<i>Apotheosis for the three</i>
<i>Evas will be performed</i>

23
00:01:35,150 --> 00:01:38,220
<i>as soon as the MAGI system</i>
<i>is reactivated.</i>

24
00:01:38,220 --> 00:01:42,060
<i>Operation confirmed. Steps 450</i>
<i>through 670 are omitted.</i>

25
00:01:42,060 --> 00:01:44,060
<i>Command has granted approval.</i>

26
00:01:44,060 --> 00:01:45,990
You're fast, Maya, that's
what makes you you!

27
00:01:45,990 --> 00:01:48,830
Of course, I am. You trained me.

28
00:01:48,830 --> 00:01:52,000
Wait a second, A-8 would
be faster there.

29
00:01:52,000 --> 00:01:53,490
Let me do that.

30
00:01:54,200 --> 00:01:56,340
Well, she was my teacher.

31
00:01:56,340 --> 00:01:59,270
How's it going? Are you finished
giving the MAGI their check-up?

32
00:01:59,270 --> 00:02:03,750
Almost done. As promised, it'll be
over before today's test begins.

33
00:02:03,750 --> 00:02:05,210
You're something else, Ritsuko.

34
00:02:05,210 --> 00:02:08,080
You have three impossible tasks,
yet you still beat the schedule.

35
00:02:08,080 --> 00:02:09,610
That one's cold.

36
00:02:13,060 --> 00:02:16,460
<i>All three MAGI systems have</i>
<i>entered self-diagnostic mode.</i>

37
00:02:16,960 --> 00:02:19,900
<i>The 127th routine maintenance</i>
<i>has been completed.</i>

38
00:02:19,900 --> 00:02:22,460
<i>Confirmed. Well done, guys.</i>

39
00:02:22,460 --> 00:02:24,520
<i>Take a break until the test begins.</i>

40
00:02:31,670 --> 00:02:33,160
Everything checked out.

41
00:02:33,840 --> 00:02:36,210
As usual, mother's in
good shape, but...

42
00:02:36,210 --> 00:02:38,940
Is it just me getting older?

43
00:02:39,100 --> 00:02:42,000
Episode 13
Angel Invades

44
00:02:42,720 --> 00:02:45,890
You want me to take off
my clothes again?

45
00:02:45,890 --> 00:02:48,620
<i>The next chamber is an ultra-clean</i>
<i>room environment.</i>

46
00:02:48,620 --> 00:02:51,490
<i>Just taking a shower and changing</i>
<i>your undergarments is insufficient.</i>

47
00:02:51,490 --> 00:02:56,330
Why do I have to go through all
this for a simple autopilot test?

48
00:02:56,330 --> 00:03:01,570
<i>With the advance of time, Eva</i>
<i>technology also needs to advance.</i>

49
00:03:01,570 --> 00:03:03,970
<i>To do so, we need a constant</i>
<i>influx of new data.</i>

50
00:03:07,780 --> 00:03:10,580
All right, I'm here, just
the way you wanted.

51
00:03:10,580 --> 00:03:13,280
Butt-naked and run through the
wash cycle seventeen times.

52
00:03:13,880 --> 00:03:16,250
<i>Now, I want all three of</i>
<i>you to stay that way</i>

53
00:03:16,250 --> 00:03:18,980
<i>as you walk through the room</i>
<i>and board the entry plug.</i>

54
00:03:20,290 --> 00:03:23,030
<i>Don't worry. The video recorders</i>
<i>have been shut off.</i>

55
00:03:23,030 --> 00:03:25,130
<i>We do respect your privacy.</i>

56
00:03:25,130 --> 00:03:29,260
That isn't the point! This is
a very personal thing!

57
00:03:29,260 --> 00:03:31,870
<i>This test's purpose is to remove</i>
<i>interference from your plug suits,</i>

58
00:03:31,870 --> 00:03:35,100
<i>and monitor the harmonics</i>
<i>directly from your bodies.</i>

59
00:03:35,100 --> 00:03:36,510
<i>Asuka, that's an order.</i>

60
00:03:36,510 --> 00:03:39,740
All right! But I don't want
anybody peeking, okay?

61
00:03:41,780 --> 00:03:44,580
<i>All pilots are ready for entry.</i>

62
00:03:45,280 --> 00:03:46,550
Start the test.

63
00:03:46,550 --> 00:03:52,000
<i>Beginning the test.</i>
<i>Initiate autopilot recording.</i>

64
00:03:52,000 --> 00:03:53,420
<i>Inserting simulation plug.</i>

65
00:03:55,890 --> 00:03:58,620
<i>Connecting simulation</i>
<i>bodies to the system.</i>

66
00:04:00,230 --> 00:04:03,030
The simulation plugs are now
under the MAGI's control.

67
00:04:03,730 --> 00:04:07,540
Wow, that was really fast!
The MAGI are magnificent!

68
00:04:07,540 --> 00:04:10,340
It's hard to believe that the first
experiment took a whole week.

69
00:04:10,340 --> 00:04:12,710
According to the schedule, the
test will end in three hours.

70
00:04:13,710 --> 00:04:15,310
<i>How do you feel?</i>

71
00:04:15,310 --> 00:04:16,710
It feels odd.

72
00:04:16,710 --> 00:04:19,620
Yes, it's different from
the other times.

73
00:04:19,620 --> 00:04:21,620
Something's wrong
with my senses.

74
00:04:21,620 --> 00:04:25,150
My right arm is all I can feel
clearly. Everything else is fuzzy.

75
00:04:25,150 --> 00:04:27,960
<i>Rei, imagine moving</i>
<i>your right hand.</i>

76
00:04:27,960 --> 00:04:29,450
Yes, Ma'am.

77
00:04:35,400 --> 00:04:37,130
Data collection is
proceeding nicely.

78
00:04:37,130 --> 00:04:39,070
Everything seems good so far.

79
00:04:39,070 --> 00:04:40,800
Return the MAGI to
their normal state.

80
00:04:41,740 --> 00:04:43,230
A dilemma...

81
00:04:44,870 --> 00:04:47,680
You can sure feel the creator's
personality, can't you?

82
00:04:47,680 --> 00:04:51,080
What are you talking about?
You created them, didn't you?

83
00:04:51,080 --> 00:04:53,140
You don't know anything, do you?

84
00:04:53,720 --> 00:04:58,050
That's because you never talk
about yourself like I do, Ritsuko!

85
00:04:58,050 --> 00:05:01,960
That's true. I just created
the system uplinks.

86
00:05:01,960 --> 00:05:04,290
The one who developed the basic
theorems and the main frame

87
00:05:04,290 --> 00:05:05,780
was my mother.

88
00:05:06,430 --> 00:05:07,860
Are you double checking this?

89
00:05:07,860 --> 00:05:09,300
Yes, I am.

90
00:05:09,800 --> 00:05:12,130
These are the parts that were
brought in three days ago.

91
00:05:12,630 --> 00:05:14,670
These are the parts that are
showing signs of deterioration.

92
00:05:14,670 --> 00:05:16,970
The 87th protein wall.

93
00:05:17,470 --> 00:05:20,480
With magnification, you can
see some of the spots.

94
00:05:20,480 --> 00:05:21,610
Can you tell me what it is?

95
00:05:21,610 --> 00:05:21,980
It's got to be corrosion.
Can you tell me what it is?

96
00:05:21,980 --> 00:05:23,010
It's got to be corrosion.
<i> </i>

97
00:05:23,010 --> 00:05:26,010
There are slight variations in the
temperature and conduction rates.

98
00:05:26,010 --> 00:05:29,180
Deterioration of sterilized rooms
happens a lot, an awful lot lately.

99
00:05:29,180 --> 00:05:32,490
The construction schedule was
cut by about sixty days.

100
00:05:32,490 --> 00:05:34,760
It's possible that some air bubbles
may have gotten inside.

101
00:05:34,760 --> 00:05:37,130
There are a lot of flaws in the
construction of B Wing.

102
00:05:37,130 --> 00:05:39,930
This building was built after the
Angels appeared, remember?

103
00:05:39,930 --> 00:05:43,500
You can't blame anyone.
Everybody was so exhausted then.

104
00:05:43,500 --> 00:05:45,570
Take care of it by tomorrow.

105
00:05:45,570 --> 00:05:47,240
Otherwise, Ikari will be jumping
all over our asses for it.

106
00:05:47,240 --> 00:05:48,730
Understood.

107
00:05:53,080 --> 00:05:54,380
Another water leak?

108
00:05:54,380 --> 00:05:57,880
No, it's some kind of corrosion in
the protein wall above this floor.

109
00:05:57,880 --> 00:05:59,280
Wonderful.

110
00:05:59,280 --> 00:06:00,650
Could it have any effect
on this test?

111
00:06:00,650 --> 00:06:02,120
No, not at the moment.

112
00:06:02,120 --> 00:06:03,720
Then, let's continue.

113
00:06:03,720 --> 00:06:07,020
We can't abort experiments due to
minor technical problems.

114
00:06:07,020 --> 00:06:08,860
Otherwise, Commander Ikari will
be jumping all over our asses.

115
00:06:08,860 --> 00:06:09,600
Understood.

116
00:06:09,600 --> 00:06:11,060
Synchronization
position is correct.

117
00:06:11,060 --> 00:06:16,100
<i>Connecting the simulation plugs to</i>
<i>the Evas via the simulation bodies.</i>

118
00:06:16,100 --> 00:06:17,800
Contact with Eva Unit 00
has been confirmed.

119
00:06:18,800 --> 00:06:21,860
<i>AT Field will be generated on two.</i>

120
00:06:31,450 --> 00:06:32,450
What's happening?!

121
00:06:32,450 --> 00:06:35,350
<i>We've got a contamination alert</i>
<i>in the Sigma unit on A Floor.</i>

122
00:06:35,350 --> 00:06:38,390
The 87th protein wall is corroding
and releasing heat.

123
00:06:38,390 --> 00:06:40,660
We've detected an abnormality
in the 6th pipe as well.

124
00:06:40,660 --> 00:06:45,060
Corrosion of the protein wall is
increasing at an incredible rate!

125
00:06:45,060 --> 00:06:48,260
Abort the experiment.
Shut off the 6th pipe.

126
00:06:48,260 --> 00:06:49,750
Right!

127
00:06:54,040 --> 00:06:57,440
Numbers 60, 38 and 39
are all closed.

128
00:06:57,440 --> 00:06:59,470
Corrosion has occurred in 6-42.

129
00:06:59,470 --> 00:07:02,640
No effect! Corrosion is spreading
along the walls.

130
00:07:02,640 --> 00:07:04,130
Prepare the polysomes.

131
00:07:09,320 --> 00:07:12,780
Set laser power at maximum.
Shoot the invasive particles.

132
00:07:15,390 --> 00:07:18,290
Corrosion has reached 6-58.
It's here!

133
00:07:30,770 --> 00:07:32,260
Rei!

134
00:07:33,880 --> 00:07:36,080
Rei's simulation body is moving.

135
00:07:36,080 --> 00:07:37,570
Impossible!

136
00:07:45,250 --> 00:07:47,190
The corrosion is still spreading.

137
00:07:47,190 --> 00:07:49,450
It's invading the simulation bodies'
active water system.

138
00:08:03,440 --> 00:08:04,140
How's Rei?!

139
00:08:04,140 --> 00:08:04,940
She's all right.
How's Rei?!

140
00:08:04,940 --> 00:08:05,640
She's all right.
Eject all plugs immediately.

141
00:08:05,640 --> 00:08:07,210
Eject all plugs immediately.

142
00:08:07,210 --> 00:08:08,700
Hurry up with that laser!

143
00:08:20,460 --> 00:08:21,890
An AT Field?!

144
00:08:21,890 --> 00:08:23,380
Impossible!

145
00:08:29,460 --> 00:08:30,930
What is it?

146
00:08:30,930 --> 00:08:32,800
The pattern analysis is blue.

147
00:08:32,800 --> 00:08:34,330
There's no question. It's an Angel.

148
00:08:37,710 --> 00:08:40,880
An Angel?! You let an
Angel get inside?

149
00:08:40,880 --> 00:08:42,440
<i>I'm sorry, Sir.</i>

150
00:08:42,440 --> 00:08:43,980
This isn't the time for excuses.

151
00:08:43,980 --> 00:08:46,050
I want a physical shut down
of Central Dogma.

152
00:08:46,050 --> 00:08:47,880
Isolate it from Sigma Unit.

153
00:08:47,880 --> 00:08:49,990
<i>Initiating physical shut down</i>
<i>of Central Dogma.</i>

154
00:08:49,990 --> 00:08:50,750
<i>Isolating from Sigma Unit.</i>

155
00:08:50,750 --> 00:08:51,690
Abandon this unit! Evacuate immediately!
<i>Isolating from Sigma Unit.</i>

156
00:08:51,690 --> 00:08:53,210
Abandon this unit! Evacuate immediately!
<i> </i>

157
00:08:56,990 --> 00:08:58,480
What the hell are you
doing? Hurry!

158
00:09:02,060 --> 00:09:04,870
<i>Isolating Sigma Unit from B Floor.</i>

159
00:09:04,870 --> 00:09:08,230
<i>Closing all partitions. All area</i>
<i>personnel must evacuate.</i>

160
00:09:09,200 --> 00:09:12,000
I know. Please take care of it.

161
00:09:14,240 --> 00:09:15,510
Stop the alarm.

162
00:09:15,510 --> 00:09:15,740
Stopping the alarm, Sir.
Stop the alarm.

163
00:09:15,740 --> 00:09:17,510
Stopping the alarm, Sir.
<i> </i>

164
00:09:18,510 --> 00:09:20,950
This is a malfunction, an error
in the alarm system.

165
00:09:20,950 --> 00:09:23,320
Report that to both the Japanese
government and the committee.

166
00:09:23,320 --> 00:09:24,520
Yes, Sir!

167
00:09:24,520 --> 00:09:26,250
The contaminated area
is still descending.

168
00:09:26,250 --> 00:09:29,120
It's spreading all over Sigma
Unit from the Pribnow Box!

169
00:09:30,090 --> 00:09:31,230
That's a critical area.

170
00:09:31,230 --> 00:09:31,590
Yes, it's too close to Adam.
That's a critical area.

171
00:09:31,590 --> 00:09:33,460
Yes, it's too close to Adam.
<i> </i>

172
00:09:33,960 --> 00:09:36,300
Stop the corrosion within
Sigma Unit!

173
00:09:36,300 --> 00:09:39,430
If necessary, sacrifice the Geo
Front. What's the Evas' status?

174
00:09:39,430 --> 00:09:41,140
Ready in seventh cage.

175
00:09:41,140 --> 00:09:43,340
We can launch them as soon
as the pilots are recovered.

176
00:09:43,340 --> 00:09:46,670
There's no need to wait for the
pilots. Launch them immediately.

177
00:09:47,440 --> 00:09:52,050
Launch Unit 01 first. Sacrifice
the other two if necessary.

178
00:09:52,050 --> 00:09:53,750
Unit 01 has top priority?

179
00:09:53,750 --> 00:09:57,250
But Sir, we can't destroy the
Angel without the Evas.

180
00:09:57,250 --> 00:10:01,420
If the Evas are contaminated first,
we'll be finished. Hurry!

181
00:10:01,420 --> 00:10:02,910
Roger!

182
00:10:04,390 --> 00:10:06,730
<i>All of Central Dogma</i>
<i>under Sigma Unit</i>

183
00:10:06,730 --> 00:10:09,430
<i>will be shut down in sixty seconds.</i>

184
00:10:09,430 --> 00:10:09,560
So that's the Angel.
<i>will be shut down in sixty seconds.</i>

185
00:10:09,560 --> 00:10:11,070
So that's the Angel.
<i>Thirty seconds until activation of vacuum pump.</i>

186
00:10:11,070 --> 00:10:13,130
Time to take a break.
<i>Thirty seconds until activation of vacuum pump.</i>

187
00:10:21,180 --> 00:10:23,650
<i>Central Dogma has been</i>
<i>completely sealed.</i>

188
00:10:23,650 --> 00:10:27,020
<i>Mega-depth facilities are entirely</i>
<i>occupied by the intruder.</i>

189
00:10:27,020 --> 00:10:29,880
Well now, how will we fight off
an Angel without an Eva?

190
00:10:29,880 --> 00:10:32,400
Neon Genesis
Evangelion

191
00:10:42,040 --> 00:10:44,480
Look, this is the border between
the normal and heavy water.

192
00:10:44,480 --> 00:10:45,880
There's a higher level
of oxygen here.

193
00:10:45,880 --> 00:10:47,710
Their preference is pretty obvious.

194
00:10:48,980 --> 00:10:50,620
The place where ozone
is vented in

195
00:10:50,620 --> 00:10:53,890
to maintain aseptic conditions
isn't contaminated.

196
00:10:53,890 --> 00:10:56,090
So does that mean that its
weakness is ozone?

197
00:10:56,090 --> 00:10:57,580
It would seem so.

198
00:11:02,330 --> 00:11:05,130
Injecting ozone. Ozone
concentration is increasing.

199
00:11:05,630 --> 00:11:07,120
It's working, all right.

200
00:11:08,470 --> 00:11:09,960
Will this work?

201
00:11:11,740 --> 00:11:14,140
Zero A and Zero B seem
to be recovering.

202
00:11:14,140 --> 00:11:16,280
The area around the pipes is
getting back to normal.

203
00:11:16,280 --> 00:11:18,680
The central portion is proving
a little more difficult.

204
00:11:18,680 --> 00:11:20,510
All right, inject more ozone.

205
00:11:23,920 --> 00:11:25,410
This isn't right.

206
00:11:26,120 --> 00:11:27,920
What? It's increasing?

207
00:11:27,920 --> 00:11:30,560
Something is wrong. Heat
levels are increasing.

208
00:11:30,560 --> 00:11:32,960
The contaminated area
is spreading again.

209
00:11:32,960 --> 00:11:35,460
The ozone is no longer
having any effect.

210
00:11:35,460 --> 00:11:37,830
Now it's absorbing the ozone.

211
00:11:37,830 --> 00:11:39,320
Stop the ozone injection!

212
00:11:40,370 --> 00:11:42,070
Amazing...

213
00:11:42,070 --> 00:11:43,590
It's evolving.

214
00:11:45,570 --> 00:11:46,540
What's wrong?

215
00:11:46,540 --> 00:11:47,080
Something's hacking into
the sub-computer.

216
00:11:47,080 --> 00:11:48,510
Something's hacking into
the sub-computer.

217
00:11:48,510 --> 00:11:49,980
The intruder hasn't
been identified.

218
00:11:49,980 --> 00:11:53,510
Not now! Dealing with C-mode.

219
00:11:53,510 --> 00:11:56,650
Unfreeze the barrier.
Open a decoy entry.

220
00:11:56,650 --> 00:11:58,390
Decoy entry has been avoided.

221
00:11:58,390 --> 00:11:59,690
T-minus eighteen seconds
to completion of trace.

222
00:11:59,690 --> 00:11:59,890
T-minus eighteen seconds
to completion of trace.

223
00:11:59,890 --> 00:12:00,850
Spreading barrier.

224
00:12:01,360 --> 00:12:02,820
Barrier has been penetrated.

225
00:12:02,820 --> 00:12:04,930
Open another false entry.

226
00:12:04,930 --> 00:12:06,830
No human being could do this.

227
00:12:06,830 --> 00:12:09,530
Trace complete. The hacker
is inside this facility!

228
00:12:09,530 --> 00:12:12,560
It's in B-Wing, in the Pribnow Box!

229
00:12:18,770 --> 00:12:20,710
Optical pattern is changing.

230
00:12:20,710 --> 00:12:22,940
Those glowing lines look
like electronic circuits.

231
00:12:22,940 --> 00:12:24,810
This is just like a computer.

232
00:12:24,810 --> 00:12:26,300
Opening decoy entry.

233
00:12:26,980 --> 00:12:29,150
It failed. There's interference.

234
00:12:29,150 --> 00:12:31,090
Cut off the main cable.

235
00:12:31,090 --> 00:12:33,090
<i>Negative, it refuses to</i>
<i>accept the command.</i>

236
00:12:33,090 --> 00:12:34,490
Fire the laser.

237
00:12:34,490 --> 00:12:34,660
It's generating an AT Field.
No effect.

238
00:12:34,660 --> 00:12:36,650
It's generating an AT Field.
No effect.

239
00:12:37,160 --> 00:12:40,690
It is accessing the main security
bank. It's cracking the pass code.

240
00:12:41,360 --> 00:12:44,230
Twelfth digit... sixteenth digit...
D word has been cleared!

241
00:12:44,730 --> 00:12:47,170
It's broken into the main banks!

242
00:12:48,100 --> 00:12:50,770
It's reading the main bank.
We can't stop it.

243
00:12:50,770 --> 00:12:52,740
What does it want?

244
00:12:52,740 --> 00:12:54,510
Scanning the main directories.

245
00:12:54,510 --> 00:12:57,010
This code is... my God!

246
00:12:57,010 --> 00:12:58,670
It's going after the MAGI!

247
00:13:03,890 --> 00:13:05,820
Shut down I/O system.

248
00:13:08,190 --> 00:13:09,560
Countdown!

249
00:13:09,560 --> 00:13:10,790
Three... Two...

250
00:13:10,790 --> 00:13:12,280
One!

251
00:13:14,760 --> 00:13:16,350
We can't shut it down!

252
00:13:16,860 --> 00:13:18,500
The Angel is intruding further
into the computers.

253
00:13:18,500 --> 00:13:20,020
It's made contact with Melchior.

254
00:13:21,940 --> 00:13:24,340
It's no good! The Angel is
taking over Melchior.

255
00:13:26,110 --> 00:13:28,580
Melchior is being re-programmed
by the Angel.

256
00:13:29,580 --> 00:13:34,220
<i>Melchior's self-destruct</i>
<i>has been initiated.</i>

257
00:13:34,220 --> 00:13:37,420
Overruled. Overruled.

258
00:13:37,420 --> 00:13:38,920
Melchior is hacking into Balthasar!
Overruled. Overruled.

259
00:13:38,920 --> 00:13:41,180
Melchior is hacking into Balthasar!
<i> </i>

260
00:13:43,190 --> 00:13:44,950
Damn, it's too fast!

261
00:13:47,260 --> 00:13:48,750
What calculation speed!

262
00:13:57,100 --> 00:13:58,740
Change the logic mode.

263
00:13:58,740 --> 00:14:00,880
Change synchronization code
to every fifteen seconds.

264
00:14:00,880 --> 00:14:02,370
Roger!

265
00:14:07,520 --> 00:14:09,450
How much time did we buy?

266
00:14:09,450 --> 00:14:12,320
At least two hours, I think.

267
00:14:12,320 --> 00:14:14,880
The MAGI have become
our enemy.

268
00:14:22,760 --> 00:14:24,330
This Angel must be composed of
a group of micro-machines,

269
00:14:24,330 --> 00:14:26,660
each the size of a virus.

270
00:14:28,440 --> 00:14:30,470
These micro-machines group
together to form colonies.

271
00:14:30,470 --> 00:14:33,340
In a very short period of time, they
have exponentially evolved

272
00:14:33,340 --> 00:14:35,880
to form a sophisticated
intelligence circuit.

273
00:14:35,880 --> 00:14:37,040
Evolved...

274
00:14:37,040 --> 00:14:37,380
Yes.
Evolved...

275
00:14:37,380 --> 00:14:38,650
Yes.
<i> </i>

276
00:14:38,650 --> 00:14:41,520
They're continuously
changing themselves

277
00:14:41,520 --> 00:14:45,120
to form the best system to cope
with any environment.

278
00:14:45,120 --> 00:14:49,290
That's their survival mechanism
as a life form.

279
00:14:49,290 --> 00:14:51,590
Against an enemy that evolves to
overcome its weaknesses

280
00:14:51,590 --> 00:14:54,760
the only effective counter measure
is to eliminate the host

281
00:14:54,760 --> 00:14:56,200
and let the parasite die with it.

282
00:14:56,700 --> 00:14:59,200
The only option is to order the
MAGI to commit suicide.

283
00:14:59,200 --> 00:15:01,770
I propose the physical elimination
of the MAGI.

284
00:15:01,770 --> 00:15:02,870
That's impossible.

285
00:15:02,870 --> 00:15:05,610
Destroying the MAGI means
destroying headquarters itself.

286
00:15:05,610 --> 00:15:08,610
Then I officially request it on
behalf of the Operations Division.

287
00:15:08,610 --> 00:15:10,040
I reject it.

288
00:15:10,040 --> 00:15:12,150
This is a matter for the
Technology Department.

289
00:15:12,150 --> 00:15:13,740
Why are you being so
mule-headed?!

290
00:15:15,280 --> 00:15:17,550
This situation is a result of
my carelessness.

291
00:15:19,120 --> 00:15:21,160
Why do you always have
to be like this?

292
00:15:21,160 --> 00:15:23,360
You always take the responsibility
on your own shoulders

293
00:15:23,360 --> 00:15:25,190
and avoiding depending
on anyone.

294
00:15:28,130 --> 00:15:31,770
As long as this Angel keeps
evolving, we have a chance.

295
00:15:31,770 --> 00:15:33,470
Expedite its evolution?

296
00:15:33,470 --> 00:15:34,640
Yes.

297
00:15:34,640 --> 00:15:38,340
The end of evolution is
self-destruction. Death itself.

298
00:15:38,340 --> 00:15:42,240
Thus, we just need to accelerate
its evolution.

299
00:15:42,780 --> 00:15:45,580
If the Angel considers it the only
practical means of survival,

300
00:15:45,580 --> 00:15:48,180
it may choose to co-exist
with the MAGI system.

301
00:15:48,180 --> 00:15:50,380
But how?

302
00:15:50,920 --> 00:15:53,220
If the Angel is a computer itself,

303
00:15:53,220 --> 00:15:55,260
we can counter-hack it by
connecting Casper to the Angel

304
00:15:55,260 --> 00:16:00,600
and uploading a self-destruct
program, but...

305
00:16:00,600 --> 00:16:04,900
At the same time, we'll be turning
off the barrier to the Angel.

306
00:16:04,900 --> 00:16:09,100
So either Casper or the Angel,
whichever is faster, will win.

307
00:16:09,100 --> 00:16:09,800
Yes.

308
00:16:09,800 --> 00:16:10,610
Will the program be ready in time?
Yes.

309
00:16:10,610 --> 00:16:12,670
Will the program be ready in time?
<i> </i>

310
00:16:12,670 --> 00:16:15,270
If Casper is taken over first,
it'll all be over.

311
00:16:18,150 --> 00:16:19,910
I keep my promises.

312
00:16:19,910 --> 00:16:23,080
<i>Red alert! Red alert!</i>

313
00:16:23,080 --> 00:16:26,890
<i>An emergency has occurred</i>
<i>in NERV Headquarters.</i>

314
00:16:26,890 --> 00:16:30,150
<i>All D-class personnel</i>
<i>must evacuate.</i>

315
00:16:39,970 --> 00:16:42,600
What are those?

316
00:16:49,910 --> 00:16:51,350
These are notes left
by the developer.

317
00:16:51,350 --> 00:16:55,780
My gosh! These are access codes!
MAGI's access codes!

318
00:16:55,780 --> 00:16:58,680
It's like a special map to all of
the MAGI's back doors.

319
00:16:59,450 --> 00:17:01,260
Am I allowed to see these?

320
00:17:01,260 --> 00:17:04,660
I can't believe it! This is INT-C!

321
00:17:06,030 --> 00:17:09,460
With these we can program much
faster than we thought!

322
00:17:12,370 --> 00:17:15,490
Thank you, Mom. We can make it.

323
00:17:27,210 --> 00:17:28,700
Give me the wrench.

324
00:17:31,150 --> 00:17:34,090
Doesn't this remind you
of our college days?

325
00:17:34,090 --> 00:17:35,920
Now, board number twenty-five.

326
00:17:41,100 --> 00:17:44,220
Hey, how about telling me about
the MAGI? Just a little?

327
00:17:45,130 --> 00:17:47,100
It's a long story.

328
00:17:47,100 --> 00:17:49,590
A long, boring story.

329
00:17:50,500 --> 00:17:53,010
Do you know about personality
transplant OS?

330
00:17:53,010 --> 00:17:56,410
Yes, it's for implanting an
individual's personality

331
00:17:56,410 --> 00:18:00,050
into a seventh generation
computer so it can think.

332
00:18:00,050 --> 00:18:03,280
The same technology is used
for operating the Evas.

333
00:18:03,280 --> 00:18:05,750
I've heard MAGI's programming
used one of the first test subjects.

334
00:18:07,120 --> 00:18:11,080
My mother developed
the technology.

335
00:18:12,330 --> 00:18:15,430
So, it was her personality
that was transplanted?

336
00:18:15,430 --> 00:18:16,920
Right!

337
00:18:26,470 --> 00:18:30,640
In a very real sense, these
brains are my mother.

338
00:18:31,850 --> 00:18:34,320
Is that why you wanted
to protect the MAGI?

339
00:18:34,320 --> 00:18:38,750
I don't think so. I didn't
really like my mom.

340
00:18:39,520 --> 00:18:41,650
This was a decision as a scientist.

341
00:18:42,320 --> 00:18:43,960
It's starting!

342
00:18:43,960 --> 00:18:46,050
Balthasar is being taken over!

343
00:18:46,560 --> 00:18:50,100
<i>The self-destruct sequence has</i>
<i>been initiated by the computer.</i>

344
00:18:50,100 --> 00:18:50,500
Has it begun yet?!
<i> </i>
<i> </i>

345
00:18:50,500 --> 00:18:51,300
Has it begun yet?!
<i>Destruct will be triggered twenty</i>
<i>seconds after all three AI consent.</i>

346
00:18:51,300 --> 00:18:55,340
<i>Destruct will be triggered twenty</i>
<i>seconds after all three AI consent.</i>

347
00:18:55,340 --> 00:19:03,640
<i>Destruction will encompass Geoid</i>
<i>Depth -280, -140 and Floor 0.</i>

348
00:19:03,640 --> 00:19:06,910
<i>Special Command 582 requires the consent...</i>

349
00:19:06,910 --> 00:19:07,180
Balthasar is now invading Casper!
<i>Special Command 582 requires the consent...</i>

350
00:19:07,180 --> 00:19:09,350
Balthasar is now invading Casper!
<i>...of two computers to cancel the action.</i>

351
00:19:09,350 --> 00:19:10,320
It's faster than us!
<i>...of two computers to cancel the action.</i>

352
00:19:10,320 --> 00:19:11,810
What speed!

353
00:19:15,690 --> 00:19:18,560
<i>T-minus twenty to self-destruct.</i>

354
00:19:18,560 --> 00:19:19,530
My God!

355
00:19:19,530 --> 00:19:20,060
Casper will be taken over in eighteen seconds.
My God!

356
00:19:20,060 --> 00:19:22,030
Casper will be taken over in eighteen seconds.
<i> </i>

357
00:19:22,030 --> 00:19:25,430
<i>T-minus fifteen to self-destruct.</i>

358
00:19:25,430 --> 00:19:26,730
Ritsuko, hurry!

359
00:19:26,730 --> 00:19:29,600
Relax. I've got almost one whole second to spare.
<i>T-minus ten to self-destruct.</i>

360
00:19:29,600 --> 00:19:29,800
Only one?!
<i> </i>

361
00:19:29,800 --> 00:19:30,970
Only one?!
<i>9...</i>

362
00:19:30,970 --> 00:19:31,870
At least it's not a zero or a minus.
<i>8...</i>

363
00:19:31,870 --> 00:19:32,910
At least it's not a zero or a minus.
<i>7...</i>

364
00:19:32,910 --> 00:19:33,040
<i>7...</i>

365
00:19:33,040 --> 00:19:33,510
<i>6...</i>

366
00:19:33,510 --> 00:19:34,210
Maya!
<i>6...</i>

367
00:19:34,210 --> 00:19:35,310
We can do it!
<i>5...</i>

368
00:19:35,310 --> 00:19:36,280
<i>4...</i>

369
00:19:36,280 --> 00:19:37,340
<i>3...</i>

370
00:19:37,340 --> 00:19:37,410
<i>2...</i>

371
00:19:37,410 --> 00:19:38,410
Hit it!
<i>2...</i>

372
00:19:38,410 --> 00:19:39,580
<i>1...</i>

373
00:19:39,580 --> 00:19:41,070
<i>Zero.</i>

374
00:19:52,530 --> 00:19:56,200
<i>Self-destruct has been canceled</i>
<i>by the computer.</i>

375
00:19:56,200 --> 00:19:57,530
All right!
<i> </i>

376
00:19:57,530 --> 00:19:59,030
All right!
<i>Special Command 582 is also canceled.</i>

377
00:19:59,030 --> 00:20:01,600
<i>Special Command 582 is also canceled.</i>

378
00:20:01,600 --> 00:20:04,300
<i>The MAGI are returning</i>
<i>to normal mode.</i>

379
00:20:15,080 --> 00:20:18,390
<i>The red alert has been canceled.</i>
<i>The red alert has been canceled.</i>

380
00:20:18,390 --> 00:20:20,860
<i>All hands return to first stage alert.</i>

381
00:20:20,860 --> 00:20:22,720
What's going on outside?
<i>All hands return to first stage alert.</i>

382
00:20:25,030 --> 00:20:28,830
Jeez, I can't get out with
no clothes on!

383
00:20:29,330 --> 00:20:32,130
Somebody, help me fast!

384
00:20:34,040 --> 00:20:38,740
<i>Sigma Unit released. T-minus zero</i>
<i>three to MAGI reactivation.</i>

385
00:20:41,240 --> 00:20:44,710
I'm getting old. Staying up for
these all-nighters is rough.

386
00:20:44,710 --> 00:20:47,580
You kept your promise again.

387
00:20:47,580 --> 00:20:49,180
Good job.

388
00:20:49,180 --> 00:20:50,670
Thank you.

389
00:20:55,160 --> 00:20:59,350
This is the first time I've ever
really appreciated your coffee.

390
00:21:00,590 --> 00:21:03,300
The night before she died,
my mother told me

391
00:21:03,300 --> 00:21:05,560
that the MAGI are three
aspects of herself.

392
00:21:06,500 --> 00:21:08,470
Herself as a scientist.

393
00:21:08,470 --> 00:21:10,040
Herself as a mother.

394
00:21:10,040 --> 00:21:11,810
Herself as a woman.

395
00:21:11,810 --> 00:21:15,410
The three aspects of her struggle
for dominance inside the MAGI.

396
00:21:15,410 --> 00:21:18,170
She intentionally implanted the
dilemmas of human experience.

397
00:21:18,750 --> 00:21:21,580
Actually, each of the three
programs are slightly different.

398
00:21:23,320 --> 00:21:25,750
I don't think I'll ever
be a mother,

399
00:21:25,750 --> 00:21:28,360
and I don't really understand
her as a mother.

400
00:21:28,360 --> 00:21:31,550
I respected her as a scientist.

401
00:21:32,260 --> 00:21:35,390
However, as a woman, I hated her.

402
00:21:37,360 --> 00:21:39,330
You're rather talkative today.

403
00:21:39,330 --> 00:21:40,820
Only sometimes.

404
00:21:46,270 --> 00:21:50,440
Casper contains the program
of her as a woman.

405
00:21:51,110 --> 00:21:55,240
She stayed a woman to the last.
How totally like my mother.

406
00:21:55,800 --> 00:22:00,750
<i>To be continued...</i>

407
00:23:06,100 --> 00:23:07,000
Preview

408
00:23:07,400 --> 00:23:09,600
NERV and Seele manage the Human
Instrumentality Project behind the scenes.

409
00:23:09,600 --> 00:23:11,390
They will revise the present
and the future of NERV.

410
00:23:11,400 --> 00:23:15,500
Are all the incidents simply just a
realization of a given scenario ?

411
00:23:15,500 --> 00:23:18,000
Next time:
"Seele, Throne of the Soul"

412
00:23:18,000 --> 00:23:20,200
And of course, service, service.

)"; cout << s<<endl;
//for (unsigned int i(0); i>s.length(); i++)
//cout << s[i];
cout<<string("eee");
	String t("MoMoo"); //cout<< t.compare_NC("Momoo")<<endl; 
	char x('a');x-=32;
; cout << x; x=tolower(x); cout<<x<<endl;
cout <<t.tolower() <<"  " <<t<<endl;
	cout<< t.compare("momo"); 
}
