#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <chrono> 

using namespace std;
using specialINT = unsigned long long int;

tuple<map<int, vector<pair<int, int>>>, set<int>, int*> tableBuilder(const vector<int>& inputVector);
specialINT numSquareCombination(map<int, vector<pair<int, int>>>& pairMAP, set<int>& elementList, int* lookupTable);

int main() {

	vector<int> sampleSpecial01
	{
		439479, 439479, 110613, 110613, 110613, 822090, 822090, 822090, 321031, 321031, 321031, 119610, 119610, 119610, 224644, 224644, 224644, 213512, 213512, 213512, 657697, 657697, 657697, 470140, 470140, 470140, 36621, 36621, 36621, 994366, 994366, 994366, 323591, 323591, 323591, 419268, 419268, 419268, 36672, 36672, 36672, 332161, 332161, 332161, 23558, 23558, 23558, 170429, 170429, 170429, 114086, 114086, 114086, 71516, 71516, 71516, 901379, 901379, 901379, 153951, 153951, 153951, 539100, 539100, 539100, 493462, 493462, 493462, 414021, 414021, 414021, 700315, 700315, 700315, 455190, 455190, 455190, 936707, 936707, 936707, 48908, 48908, 48908, 365861, 365861, 365861, 162166, 162166, 162166, 977996, 977996, 977996, 601735, 601735, 601735, 893538, 893538, 893538, 963757, 963757, 963757, 637848, 637848, 637848, 58523, 58523, 58523, 377889, 377889, 377889, 67444, 67444, 67444, 490971, 490971, 490971, 492751, 492751, 492751, 651177, 651177, 651177, 291084, 291084, 291084, 161578, 161578, 161578, 945527, 945527, 945527, 85136, 85136, 85136, 673984, 673984, 673984, 369629, 369629, 369629, 25118, 25118, 25118, 60165, 60165, 60165, 281188, 281188, 281188, 752765, 752765, 752765, 371214, 371214, 371214, 160606, 160606, 160606, 436213, 436213, 436213, 63771, 63771, 63771, 33815, 33815, 33815, 298111, 298111, 298111, 987253, 987253, 987253, 761292, 761292, 761292, 474878, 474878, 474878, 17065, 17065, 17065, 710999, 710999, 710999, 501087, 501087, 501087, 1079, 1079, 1079, 793820, 793820, 793820, 551523, 551523, 551523, 983344, 983344, 983344, 966639, 966639, 966639, 113797, 113797, 113797, 963017, 963017, 963017, 88265, 88265, 88265, 504223, 504223, 504223, 990951, 990951, 990951, 410050, 410050, 410050, 833034, 833034, 833034, 745022, 745022, 745022, 13655, 13655, 13655, 747853, 747853, 747853, 774848, 774848, 774848, 59760, 59760, 59760, 879064, 879064, 879064, 603046, 603046, 603046, 352041, 352041, 352041, 17703, 17703, 17703, 454937, 454937, 454937, 482359, 482359, 482359, 701846, 701846, 701846, 798860, 798860, 798860, 50575, 50575, 50575, 286295, 286295, 286295, 187701, 187701, 187701, 984848, 984848, 984848, 601186, 601186, 601186, 543330, 543330, 543330, 572518, 572518, 572518, 789789, 789789, 789789, 1782, 1782, 1782, 77645, 77645, 77645, 666032, 666032, 666032, 643409, 643409, 643409, 33342, 33342, 33342, 307919, 307919, 307919, 707699, 707699, 707699, 925186, 925186, 925186, 952977, 952977, 952977, 635701, 635701, 635701, 129596, 129596, 129596, 830613, 830613, 830613, 594835, 594835, 594835, 678797, 678797, 678797, 392256, 392256, 392256, 586311, 586311, 586311, 575281, 575281, 575281, 368716, 368716, 368716, 7359, 7359, 7359, 265953, 265953, 265953, 380884, 380884, 380884, 13879, 13879, 13879, 845683, 845683, 845683, 306523, 306523, 306523, 689919, 689919, 689919, 556119, 556119, 556119, 634644, 634644, 634644, 626773, 626773, 626773, 498067, 498067, 498067, 887960, 887960, 887960, 711026, 711026, 711026, 411265, 411265, 411265, 184497, 184497, 184497, 244245, 244245, 244245, 544718, 544718, 544718, 116498, 116498, 116498, 58448, 58448, 58448, 741816, 741816, 741816, 309348, 309348, 309348, 549721, 549721, 549721, 493950, 493950, 493950, 104087, 104087, 104087, 524426, 524426, 524426, 38847, 38847, 38847, 857077, 857077, 857077, 796603, 796603, 796603, 553198, 553198, 553198, 46669, 46669, 46669, 515279, 515279, 515279, 215016, 215016, 215016, 327825, 327825, 327825, 894279, 894279, 894279, 341631, 341631, 341631, 692968, 692968, 692968, 265502, 265502, 265502, 270020, 270020, 270020, 872488, 872488, 872488, 733237, 733237, 733237, 144539, 144539, 144539, 654393, 654393, 654393, 139747, 139747, 139747, 856443, 856443, 856443, 30368, 30368, 30368, 575148, 575148, 575148, 52490, 52490, 52490, 354666, 354666, 354666, 687849, 687849, 687849, 887389, 887389, 887389, 273480, 273480, 273480, 34387, 34387, 34387, 721127, 721127, 721127, 848201, 848201, 848201, 717489, 717489, 717489, 480403, 480403, 480403, 52115, 52115, 52115, 518629, 518629, 518629, 591807, 591807, 591807, 396840, 396840, 396840, 812146, 812146, 812146, 414311, 414311, 414311, 355676, 355676, 355676, 845310, 845310, 845310, 856001, 856001, 856001, 105530, 105530, 105530, 740003, 740003, 740003, 589101, 589101, 589101, 873974, 873974, 873974, 381030, 381030, 381030, 958737, 958737, 958737, 706188, 706188, 706188, 41413, 41413, 41413, 976083, 976083, 976083, 5315, 5315, 5315, 291526, 291526, 291526, 56270, 56270, 56270, 690401, 690401, 690401, 377498, 377498, 377498, 703783, 703783, 703783, 96088, 96088, 96088, 12413, 12413, 12413, 299491, 299491, 299491, 549459, 549459, 549459, 802495, 802495, 802495, 402219, 402219, 402219, 208855, 208855, 208855, 175923, 175923, 175923, 633746, 633746, 633746, 38593, 38593, 38593, 654522, 654522, 654522, 940122, 940122, 940122, 668137, 668137, 668137, 953661, 953661, 953661, 833387, 833387, 833387, 58829, 58829, 58829, 746206, 746206, 746206, 461234, 461234, 461234, 284873, 284873, 284873, 237559, 237559, 237559, 29865, 29865, 29865, 462266, 462266, 462266, 672228, 672228, 672228, 957082, 957082, 957082, 806137, 806137, 806137, 56335, 56335, 56335, 347215, 347215, 347215, 166820, 166820, 166820, 771654, 771654, 771654, 650173, 650173, 650173, 534428, 534428, 534428, 613151, 613151, 613151, 345059, 345059, 345059, 149393, 149393, 149393, 889872, 889872, 889872, 789642, 789642, 789642, 265668, 265668, 265668, 554082, 554082, 554082, 650170, 650170, 650170, 810394, 810394, 810394, 109907, 109907, 109907, 945988, 945988, 945988, 946965, 946965, 946965, 211084, 211084, 211084, 999463, 999463, 999463, 805120, 805120, 805120, 741431, 741431, 741431, 865679, 865679, 865679, 254177, 254177, 254177, 443897, 443897, 443897, 807890, 807890, 807890, 507587, 507587, 507587, 609239, 609239, 609239, 460956, 460956, 460956, 455078, 455078, 455078, 773575, 773575, 773575, 58028, 58028, 58028, 97363, 97363, 97363, 3488, 3488, 3488, 977565, 977565, 977565, 145292, 145292, 145292, 874996, 874996, 874996, 179728, 179728, 179728, 68865, 68865, 68865, 913082, 913082, 913082, 196953, 196953, 196953, 325177, 325177, 325177, 340969, 340969, 340969, 362178, 362178, 362178, 467438, 467438, 467438, 35121, 35121, 35121, 529553, 529553, 529553, 510913, 510913, 510913, 907921, 907921, 907921, 178729, 178729, 178729, 120157, 120157, 120157, 802328, 802328, 802328, 546362, 546362, 546362, 379910, 379910, 379910, 748380, 748380, 748380, 895119, 895119, 895119, 52994, 52994, 52994, 678718, 678718, 678718, 854762, 854762, 854762, 405209, 405209, 405209, 349399, 349399, 349399, 431087, 431087, 431087, 367165, 367165, 367165, 885128, 885128, 885128, 27971, 27971, 27971, 536015, 536015, 536015, 577293, 577293, 577293, 81298, 81298, 81298, 464229, 464229, 464229, 628057, 628057, 628057, 867129, 867129, 867129, 394028, 394028, 394028, 258296, 258296, 258296, 593205, 593205, 593205, 3320, 3320, 3320, 349508, 349508, 349508, 821886, 821886, 821886, 610724, 610724, 610724, 559636, 559636, 559636, 729345, 729345, 729345, 757830, 757830, 757830, 607612, 607612, 607612, 66452, 66452, 66452, 638993, 638993, 638993, 363319, 363319, 363319, 222586, 222586, 222586, 821115, 821115, 821115, 212442, 212442, 212442, 136170, 136170, 136170, 67485, 67485, 67485, 405018, 405018, 405018, 668174, 668174, 668174, 660004, 660004, 660004, 807420, 807420, 807420, 492608, 492608, 492608, 854498, 854498, 854498, 939180, 939180, 939180, 34418, 34418, 34418, 21155, 21155, 21155, 741381, 741381, 741381, 632988, 632988, 632988, 259201, 259201, 259201, 488571, 488571, 488571, 342666, 342666, 342666, 98381, 98381, 98381, 364536, 364536, 364536, 346452, 346452, 346452, 326335, 326335, 326335, 734766, 734766, 734766, 998805, 998805, 998805, 643796, 643796, 643796, 847007, 847007, 847007, 798845, 798845, 798845, 696903, 696903, 696903, 728088, 728088, 728088, 891448, 891448, 891448, 59187, 59187, 59187, 82685, 82685, 82685, 403121, 403121, 403121, 514146, 514146, 514146, 880919, 880919, 880919, 739036, 739036, 739036, 197155, 197155, 197155, 862155, 862155, 862155, 901738, 901738, 901738, 160939, 160939, 160939, 283171, 283171, 283171, 493184, 493184, 493184, 533768, 533768, 533768, 748121, 748121, 748121, 290161, 290161, 290161, 138746, 138746, 138746, 85455, 85455, 85455, 514325, 514325, 514325, 78659, 78659, 78659, 896615, 896615, 896615, 379562, 379562, 379562, 906886, 906886, 906886, 477715, 477715, 477715, 28957, 28957, 28957, 104767, 104767, 104767, 142261, 142261, 142261, 607465, 607465, 607465, 945793, 945793, 945793, 282830, 282830, 282830, 420748, 420748, 420748, 418331, 418331, 418331, 365249, 365249, 365249, 535017, 535017, 535017, 68754, 68754, 68754, 361291, 361291, 361291, 687674, 687674, 687674, 940750, 940750, 940750, 977625, 977625, 977625, 646288, 646288, 646288, 814292, 814292, 814292, 578161, 578161, 578161, 807720, 807720, 807720, 881510, 881510, 881510, 862994, 862994, 862994, 713827, 713827, 713827, 854492, 854492, 854492, 277236, 277236, 277236, 894075, 894075, 894075, 401333, 401333, 401333, 120168, 120168, 120168, 243856, 243856, 243856, 723154, 723154, 723154, 722031, 722031, 722031, 182650, 182650, 182650, 815076, 815076, 815076, 333630, 333630, 333630, 81885, 81885, 81885, 892169, 892169, 892169, 563435, 563435, 563435, 213288, 213288, 213288, 436784, 436784, 436784, 503866, 503866, 503866, 517696, 517696, 517696, 683641, 683641, 683641, 49261, 49261, 49261, 53484, 53484, 53484, 327464, 327464, 327464, 537195, 537195, 537195, 268502, 268502, 268502, 913503, 913503, 913503, 355349, 355349, 355349, 212167, 212167, 212167, 112529, 112529, 112529, 708234, 708234, 708234, 569193, 569193, 569193, 550276, 550276, 550276, 493976, 493976, 493976, 222273, 222273, 222273, 334581, 334581, 334581, 95560, 95560, 95560, 282890, 282890, 282890, 934608, 934608, 934608, 578357, 578357, 578357, 175739, 175739, 175739, 40035, 40035, 40035, 313436, 313436, 313436, 742407, 742407, 742407, 62972, 62972, 62972, 521979, 521979, 521979, 595864, 595864, 595864, 62280, 62280, 62280, 87807, 87807, 87807, 894273, 894273, 894273, 643913, 643913, 643913, 78634, 78634, 78634, 571080, 571080, 571080, 163511, 163511, 163511, 148692, 148692, 148692, 828510, 828510, 828510, 934988, 934988, 934988, 214337, 214337, 214337, 358867, 358867, 358867, 184403, 184403, 184403, 361929, 361929, 361929, 531911, 531911, 531911, 695896, 695896, 695896, 520733, 520733, 520733, 595287, 595287, 595287, 777755, 777755, 777755, 951858, 951858, 951858, 551011, 551011, 551011, 758602, 758602, 758602, 266724, 266724, 266724, 12558, 12558, 12558, 809356, 809356, 809356, 226364, 226364, 226364, 291214, 291214, 291214, 927263, 927263, 927263, 113536, 113536, 113536, 557211, 557211, 557211, 175035, 175035, 175035, 955503, 955503, 955503, 506840, 506840, 506840, 962890, 962890, 962890, 39547, 39547, 39547, 518631, 518631, 518631, 41876, 41876, 41876, 417242, 417242, 417242, 435926, 435926, 435926, 797722, 797722, 797722, 114363, 114363, 114363, 375984, 375984, 375984, 548769, 548769, 548769, 20769, 20769, 20769, 650465, 650465, 650465, 724261, 724261, 724261, 36828, 36828, 36828, 629035, 629035, 629035, 842117, 842117, 842117, 559127, 559127, 559127, 377031, 377031, 377031, 298173, 298173, 298173, 606326, 606326, 606326, 573412, 573412, 573412, 499793, 499793, 499793, 587634, 587634, 587634, 579921, 579921, 579921, 392251, 392251, 392251, 365613, 365613, 365613, 536974, 536974, 536974, 593062, 593062, 593062, 778119, 778119, 778119, 862753, 862753, 862753, 486881, 486881, 486881, 908906, 908906, 908906, 288851, 288851, 288851, 945996, 945996, 945996, 831070, 831070, 831070, 554314, 554314, 554314, 17098, 17098, 17098, 250072, 250072, 250072, 437152, 437152, 437152, 403901, 403901, 403901, 858537, 858537, 858537, 495223, 495223, 495223, 8715, 3735, 1139, 3195, 8118, 7549, 7036, 1849, 8891, 6552, 3712, 8824, 5533, 6148, 4087, 2114, 1142, 9714, 3900, 9608, 8748, 6061, 8333, 6472, 6122, 9134, 4113, 1481, 5382, 9025, 5951, 3637, 4347, 9929, 3059, 5209, 5155, 6985, 5391, 6646, 5417, 5254, 2520, 7776, 5210, 4055, 6398, 4364, 5564, 6983, 6241, 9533, 9375, 6360, 5664, 6545, 6060, 5409, 5656, 1868, 8435, 3984, 8243, 5577, 5875, 6590, 8228, 9098, 1624, 5739, 9799, 1224, 7906, 9658, 8326, 6439, 9009, 5809, 9896, 3657, 3724, 9995, 6863, 8364, 5176, 3859, 1300, 1659, 2065, 9372, 3419, 7286, 3716, 4141, 3814, 6167, 4288, 8672, 3507, 9726, 6987, 8915, 7048, 3562, 10022, 5155, 4397, 1099, 2079, 5548, 1628, 3766, 4473, 6340, 5880, 2412, 6618, 9681, 1532, 9926, 1178, 6089, 7298, 9868, 2912, 1990, 4908, 9389, 8139, 9593, 6982, 1203, 9006, 5851, 5338, 9959, 7776, 6379, 5604, 5893, 5110, 4065, 10189, 8995, 2676, 4589, 9700, 6231, 3235, 5371, 10095, 8862, 5189, 9187, 7534, 8798, 6372, 8241, 7360, 9519, 4645, 8717, 2655, 8709, 6045, 2761, 5864, 9502, 4792, 8836, 9422, 8494, 7807, 8200, 9315, 5393, 9281, 7197, 8365, 3111, 4137, 7128, 1366, 7831, 5436, 2354, 3795, 2145, 7041, 3728, 1465, 1049, 2139, 9676, 5697, 8542, 3648, 7295, 1016, 6701, 9499, 1083, 3103, 1646, 1583, 6774, 5729, 9139, 2352, 1471, 5503, 7180, 2394, 9549, 2400, 4374, 4245, 6973, 3392, 2453, 1380, 1730, 1833, 4929, 5663, 8660, 3718, 7629, 2467, 8639, 8007, 1446, 8655, 7483, 4218, 7922, 1015, 6821, 7989, 3100, 9259, 4270, 3863, 6836, 5340, 6517, 9767, 4026, 7555, 5295, 4477, 4373, 7844, 2761, 5561, 9017, 2885, 9116, 7241, 9982, 7299, 1318, 1438, 9337, 3029, 3331, 5653, 1038, 6010, 5746, 8162, 7637, 1045, 3443, 6716, 10027, 4167, 3119, 3868, 4436, 9517, 8467, 9628, 5707, 8278, 3102, 9886, 1458, 1119, 4368, 8666, 7431, 9935, 10093, 6821, 5255, 4059, 4233, 4946, 8068, 6415, 3749, 2005, 6264, 8434, 3855, 2481, 9500, 7435, 8611, 1642, 6515, 4725, 5042, 6086, 1510, 4209, 8276, 2094, 7081, 6181, 6393, 4015, 9128, 5094, 2298, 7967, 7349, 8309, 1198, 8728, 5867, 1463, 4544, 7020, 2655, 1152, 2062, 3576, 7299, 3698, 6524, 2342, 9314, 6178, 7265, 4719, 5796, 4416, 9712, 2781, 7591, 1496, 5274, 2021, 1340, 8903, 8707, 6424, 5397, 2359, 7943, 10141, 7987, 9327, 5656, 6640, 2285, 1161, 5178, 4681, 5374, 2216, 3798, 1392, 3192, 7059, 2606, 6646, 1073, 8981, 1866, 8149, 4623, 8539, 3050, 1362, 7440, 1835, 9008, 4288, 2241, 3107, 6270, 7838, 9275, 1677, 2279, 3741, 8325, 9817, 8830, 6248, 7146, 6794, 6155, 5284, 3545, 8959, 8316, 1585, 5413, 6658, 7308, 5134, 6234, 6465, 3903, 2679, 9886, 9098, 4846, 6727, 7286, 6012, 3450, 5448, 1621, 1168, 7698, 8702, 7537, 2233, 5369, 5687, 9948, 4153, 9100, 4509, 5673, 8777, 6620, 6742, 9738, 6533, 2347, 8004, 4163, 9499, 7250, 8826, 7147, 5763, 2041, 3682, 5688, 4717, 9014, 7883, 4752, 7638, 9491, 1866, 6420, 4037, 3740, 5089, 2354, 7724, 3631, 6907, 4527, 5469, 2946, 3840, 3763, 1439, 5635, 6110, 6423, 9470, 8590, 4597, 2108, 5156, 5063, 7089, 5375, 4562, 3729, 7537, 5596, 8402, 8118, 7525, 5971, 9758, 6036, 2468, 7898, 8541, 8386, 5650, 2254, 5724, 3670, 9740, 4950, 7675, 7016, 8914, 6333, 3723, 8205, 2879, 2564, 7495, 8289, 3940, 9408, 3141, 7027, 3193, 6269, 5186, 9570, 7025, 9720, 8495, 5049, 6649, 9547, 3961, 3215, 6463, 2579, 3188, 9348, 1437, 5639, 6055, 9248, 2071, 3874, 3925, 8030, 4998, 5974, 4316, 9259, 5431, 4030, 8899, 7093, 1091, 9988, 6727, 4608, 6439, 10183, 9296, 3564, 9228, 5613, 2561, 4615, 8506, 4498, 2729, 3609, 2547, 10067, 2619, 1517, 6266, 9945, 4814, 8087, 8875, 3024, 5945, 3053, 6897, 3438, 9258, 7593, 6174, 9787, 6412, 2775, 7242, 5908, 4787, 6217, 1498, 4514, 9833, 9109, 6001, 6809, 4707, 8254, 7698, 4323, 8982, 6445, 1793, 9535, 8216, 8120, 1073, 4854, 7313, 7946, 2608, 8602, 5919, 5763, 9346, 9231, 3467, 1377, 1836, 3644, 2558, 5763, 9724, 4789, 4301, 7362, 1114, 6172, 6583, 6271, 7319, 4449, 4249, 7327, 4084, 7186, 5279, 2755, 3935, 3324, 8947, 9726, 4708, 5422, 7200, 1979, 3848, 3840, 7197, 7194, 7302, 1030, 3309, 8231, 2528, 6231, 2772, 5331, 6894, 4049, 1359, 7318, 6676, 7830, 8233, 9735, 7115, 1959, 9010, 6484, 3027, 5204, 5797, 1079, 1256, 3857, 4198, 6116, 4323, 2806, 2802, 3057, 8772, 5160, 5123, 3715, 4704, 5689, 1224, 1279, 2674, 2933, 6477, 6716, 1212, 6409, 2411, 4353, 6126, 2669, 7119, 6862, 7869, 6929, 8855, 3172, 4991, 3633, 10117, 5597, 3401, 6495, 4833, 10044, 9713, 1918, 2196, 7690, 4898, 2672, 1287, 3012, 4655, 3931, 3428, 4013, 2269, 1153, 3831, 4782, 9094, 10043, 8473, 1787, 6696, 7492, 7278, 1298, 4372, 2698, 1557, 5921, 4836, 6914, 6631, 4157, 7242, 5722, 8730, 1448, 2888, 5094, 4446, 7035, 5619, 2702, 7999, 5054, 9978, 1599, 7506, 5713, 6376, 3184, 7762, 5844, 6107, 8020, 10184, 7661, 1790, 3734, 6021, 2629, 1881, 4082, 5307, 3035, 3564, 3636, 4844, 7260, 4187, 9785, 2108, 6557, 6091, 3619, 6926, 4477, 9165, 9347, 9981, 5821, 1150, 2227, 6612, 3554, 8786, 6411, 7106, 1145, 4485, 5556, 3745, 5591, 7117, 1151, 3545, 2458, 9420, 3038, 3610, 5088, 6786, 1306, 9129, 1090, 3366, 4151, 9125, 8780, 1564, 3141, 2311, 1035, 1929, 6966, 6291, 9343, 5075, 9389, 1461, 5276, 4710, 7108, 1194, 8563, 7609, 9943, 9480, 8536, 2453, 9170, 7854, 5952, 8460, 3226, 5378, 3236, 3183, 4029, 9880, 8555, 2678, 6988, 6055, 5286, 4817, 4212, 6470, 9231, 6302, 8163, 1916, 9697, 1565, 4789, 5748, 8165, 7935, 1106, 7799, 4994, 6477, 9097, 6211, 3790, 10085, 3022, 6686, 6760, 2037, 9407, 6368, 2876, 7978, 3523, 1205, 8179, 7657, 5404, 5942, 5947, 1004, 5757, 5030, 1901, 9538, 1580, 1714, 6965, 8954, 4568, 8019, 4638, 2212, 2090, 3372, 5506, 7340, 9944, 2282, 5898, 3585, 1669, 7675, 9302, 10026, 5586, 1681, 4419, 1200, 8796, 5750, 3161, 9543, 1694, 9019, 2811, 2217, 7805, 9146, 1414, 9633, 3364, 3414, 8683, 7767, 4643, 5235, 7946, 4295, 4085, 1920, 4492, 3577, 3111, 4943, 4163, 6747, 6085, 5377, 9690, 1233, 9913, 9137, 5353, 5068, 3010, 3699, 3428, 10003, 4960, 7779, 8570, 4277, 4443, 9252, 3975, 1834, 9237, 2135, 6246, 2456, 3023, 9039, 3192, 5835, 2530, 7120, 5742, 5301, 3506, 5179, 2728, 7543, 7452, 5978, 9242, 1490, 6839, 5511, 1592, 2287, 5497, 7770, 4766, 4003, 5247, 1807, 6603, 5470, 5964, 2896, 7877, 2513, 5155, 1777, 7405, 5389, 1704, 9969, 7261, 5815, 1254, 5672, 8428, 9542, 10059, 9725, 3467, 2367, 4853, 7662, 9902, 4178, 2904, 3954, 6442, 8530, 9328, 9907, 9194, 8271, 5899, 2138, 5428, 9672, 6992, 4004, 9736, 4644, 4643, 10047, 7853, 1740, 1716, 8836, 1118, 7852, 8065, 4155, 7221, 8798, 5222, 5450, 9335, 8665, 2770, 3096, 4155, 7738, 5855, 2088, 8416, 5020, 5234, 5894, 3869, 8062, 7344, 4693, 7801, 1245, 1254, 7044, 6516, 9041, 7804, 9512, 4858, 7086, 6044, 10042, 7094, 2481, 6292, 6773, 6854, 1662, 1210, 10175, 1950, 6324, 3534, 3872, 9741, 5663, 7877, 1531, 3966, 1422, 4541, 5472, 5256, 1096, 7293, 6966, 6343, 9087, 4958, 8862, 3565, 3625, 3598, 7337, 6874, 5385, 7312, 8164, 8783, 7215, 7973, 8144, 3571, 4706, 2608, 4971, 2138, 3642, 7364, 7410, 5300, 1205, 8710, 2139, 5895, 2026, 6270, 9377, 3898, 5951, 3006, 9418, 8488, 8712, 4322, 5697, 8920, 6953, 2949, 5328, 3919, 9861, 8949, 9637, 6581, 1652, 3698, 2965, 3293, 8893, 4749, 5733, 7418, 7211, 3749, 5477, 9937, 3499, 5661, 2358, 3263, 8525, 1392, 4048, 4170, 5977, 5001, 9217, 4013, 2303, 8823, 5324, 8600, 8907, 9267, 8380, 6613, 2582, 7445, 8642, 2335, 8869, 6031, 8328, 9764, 8436, 9185, 8383, 8818, 9848, 2889, 8772, 1627, 7711, 7068, 7161, 1167, 4488, 1295, 7046, 7788, 4269, 9744, 9731, 9435, 9039, 9949, 2703, 9179, 10079, 8965, 9046, 9441, 3019, 2637, 2828, 9179, 2237, 8058, 9542, 1655, 5740, 5905, 5697, 5877, 1590, 10031, 4214, 2717, 2335, 4597, 5947, 1842, 9904, 4394, 1446, 1601, 1801, 1900, 2999, 9119, 3134, 3621, 1354, 8374, 1133, 1847, 3119, 1046, 3246, 6750, 7289, 4766, 7435, 1100, 6233, 7845, 8792, 9077, 9120, 6707, 7550, 1623, 3140, 2119, 5492, 6506, 6207, 9639, 8198, 2517, 7492, 3145, 10005, 8563, 1699, 8844, 7569, 7563, 9825, 6887, 2818, 9643, 1203, 3553, 4640, 8828, 7893, 5126, 2137, 3152, 1441, 4421, 6531, 10148, 8684, 4984, 2627, 8439, 3724, 5377, 9423, 1387, 5338, 5657, 9425, 8310, 7223, 7739, 5527, 3537, 5350, 8125, 5085, 3502, 3053, 4948, 5073, 3414, 8457, 6610, 5835, 6521, 7961, 2979, 1330, 7417, 8826, 4996, 8601, 9755, 3705, 9641, 4558, 4853, 6262, 5961, 7130, 7334, 3887, 4703, 3930, 8476, 9808, 9200, 1343, 2931, 7897, 7093, 9934, 8990, 7856, 5697, 4034, 5242, 7561, 4939, 9837, 1423, 4381, 1725, 1010, 8243, 9712, 2039, 4747, 5094, 2953, 6933, 6464, 9070, 7106, 6767, 1601, 8199, 3130, 4409, 10093, 3230, 9526, 9595, 4122, 5216, 1028, 1115, 6151, 7141, 3171, 4866, 8399, 9152, 1770, 3266, 3044, 7817, 4240, 8338, 1936, 8665, 7402, 7578, 10046, 2814, 3226, 5235, 8536, 7307, 9203, 4500, 2620, 3528, 1238, 9086, 8052, 2887, 7111, 7157, 1698, 9017, 7222, 4110, 5333, 1498, 1945, 4426, 6202, 8560, 5854, 6776, 2473, 2378, 3560, 5533, 6283, 9155, 5947, 2554, 6098, 7201, 3812, 7593, 7474, 7589, 4132, 1006, 8427, 6226, 5047, 3944, 4273, 3934, 6466, 2539, 8900, 4348, 2776, 5120, 5345, 8038, 3642, 1991, 7591, 4259, 5887, 1107, 5450, 2934, 6450, 7924, 5598, 7234, 8427, 4585, 5929, 3924, 5120, 8508, 3227, 5256, 4329, 7031, 4352, 10021, 4206
	};
	// ANS: 2,037,505 
	vector<int> sampleSpecial02
	{
		4, 6, 5, 7, 1, 5, 2, 10, 2, 8, 9, 6, 5, 4, 9, 10, 5, 8, 4, 1, 5, 5, 4, 5, 6, 1, 7, 8, 1, 7, 5, 8, 4, 1, 4, 4, 2, 1, 8, 3, 10, 9, 6, 5, 6, 9, 7, 10, 7, 6, 7, 7, 1, 1, 6, 6, 6, 7, 6, 3, 1, 6, 2, 2, 8, 9, 6, 9, 2, 9, 7, 6, 10, 1, 5, 7, 6, 2, 1, 1, 3, 6, 9, 6, 9, 10, 4, 10, 3, 6, 9, 4, 6, 7, 1, 10, 9, 8, 2, 9, 1, 9, 9, 6, 5, 9, 8, 10, 3, 3, 4, 8, 1, 2, 4, 7, 6, 7, 10, 6, 8, 4, 1, 8, 9, 4, 6, 9, 7, 6, 2, 2, 4, 10, 9, 4, 4, 10, 1, 3, 3, 10, 9, 10, 9, 9, 8, 7, 2, 6, 6, 9, 5, 4, 10, 9, 7, 4, 6, 9, 2, 2, 8, 6, 4, 9, 9, 10, 8, 2, 6, 10, 5, 3, 4, 6, 4, 6, 8, 8, 7, 5, 2, 9, 6, 4, 8, 3, 10, 6, 7, 9, 1, 1, 6, 2, 9, 2, 9, 4, 4, 1, 6, 1, 10, 9, 1, 3, 8, 1, 10, 6, 2, 4, 6, 1, 8, 2, 10, 5, 9, 6, 8, 4, 3, 1, 6, 7, 7, 3, 3, 8, 10, 4, 3, 8, 10, 8, 5, 8, 2, 2, 6, 3, 4, 3, 1, 5, 7, 9, 7, 8, 2, 2, 8, 8, 2, 1, 10, 3, 9, 6, 1, 4, 7, 2, 10, 9, 1, 1, 7, 3, 6, 10, 10, 10, 3, 6, 5, 7, 6, 2, 5, 2, 9, 1, 3, 7, 10, 6, 5, 7, 3, 1, 3, 6, 7, 7, 1, 2, 2, 6, 2, 5, 2, 10, 8, 10, 5, 10, 2, 9, 4, 6, 2, 1, 4, 4, 3, 2, 6, 6, 1, 3, 3, 10, 10, 10, 6, 7, 6, 2, 5, 7, 1, 10, 8, 2, 4, 4, 7, 1, 3, 1, 5, 2, 1, 6, 7, 1, 3, 7, 7, 1, 2, 1, 1, 7, 5, 5, 3, 6, 5, 3, 7, 5, 3, 10, 2, 4, 1, 10, 10, 10, 3, 1, 1, 3, 7, 4, 2, 4, 3, 8, 9, 5, 5, 5, 3, 9, 4, 2, 9, 7, 2, 6, 5, 3, 3, 4, 8, 1, 4, 6, 10, 8, 8, 10, 7, 8, 6, 9, 6, 6, 5, 9, 4, 7, 1, 3, 3, 9, 9, 5, 4, 1, 9, 9, 2, 10, 9, 5, 9, 10, 1, 9, 1, 3, 5, 10, 7, 1, 8, 7, 7, 9, 3, 6, 5, 10, 10, 3, 6, 3, 3, 4, 10, 5, 1, 6, 7, 10, 6, 3, 1, 5, 8, 6, 4, 5, 5, 6, 3, 9, 6, 1, 7, 10, 9, 7, 7, 4, 7, 4, 8, 10, 5, 8, 6, 7, 8, 7, 9, 7, 8, 4, 2, 8, 4, 5, 8, 7, 10, 10, 9, 2, 9, 4, 7, 8, 1, 5, 8, 2, 4, 6, 8, 8, 9, 6, 5, 1, 7, 2, 3, 3, 7, 3, 3, 8, 7, 8, 5, 5, 6, 2, 1, 2, 7, 10, 10, 3, 6, 8, 10, 3, 5, 3, 10, 1, 7, 4, 5, 2, 6, 5, 9, 1, 10, 3, 3, 3, 6, 4, 6, 5, 1, 6, 5, 8, 5, 9, 6, 7, 4, 5, 6, 5, 3, 6, 8, 10, 6, 6, 1, 10, 1, 7, 5, 2, 4, 4, 10, 2, 10, 1, 3, 3, 10, 2, 10, 5, 5, 6, 6, 1, 6, 7, 9, 10, 5, 4, 10, 8, 9, 5, 5, 4, 10, 6, 4, 2, 9, 1, 7, 6, 7, 4, 8, 5, 6, 8, 10, 7, 9, 10, 6, 4, 3, 10, 3, 2, 6, 3, 4, 1, 2, 6, 7, 5, 5, 5, 5, 4, 9, 10, 9, 1, 7, 4, 4, 5, 9, 5, 10, 9, 2, 9, 6, 6, 9, 8, 4, 10, 5, 8, 6, 5, 7, 3, 8, 1, 4, 9, 2, 6, 9, 7, 4, 3, 9, 1, 4, 10, 4, 3, 9, 5, 3, 9, 2, 3, 2, 8, 3, 9, 9, 1, 5, 5, 5, 6, 3, 6, 10, 8, 3, 6, 8, 7, 4, 9, 5, 1, 6, 4, 1, 4, 3, 9, 8, 1, 8, 6, 7, 6, 3, 5, 3, 4, 7, 6, 8, 8, 9, 1, 9, 10, 7, 3, 4, 1, 1, 10, 10, 5, 8, 4, 2, 9, 4, 8, 3, 4, 2, 10, 2, 2, 6, 5, 5, 8, 7, 8, 7, 4, 9, 6, 2, 3, 10, 4, 3, 1, 2, 6, 3, 10, 5, 1, 7, 3, 1, 1, 3, 6, 5, 1, 9, 4, 8, 8, 8, 4, 10, 5, 5, 10, 6, 2, 5, 8, 1, 2, 4, 7, 10, 7, 9, 8, 4, 7, 10, 2, 2, 9, 1, 1, 3, 3, 4, 4, 8, 10, 6, 5, 6, 6, 2, 2, 3, 10, 8, 4, 3, 9, 10, 3, 5, 2, 9, 3, 3, 6, 9, 9, 10, 7, 7, 6, 2, 9, 5, 6, 7, 9, 1, 3, 9, 2, 8, 5, 6, 7, 7, 5, 4, 1, 5, 7, 10, 8, 6, 5, 10, 8, 1, 5, 2, 2, 5, 2, 9, 1, 2, 5, 5, 9, 2, 8, 3, 5, 10, 7, 4, 6, 2, 4, 8, 8, 6, 7, 2, 1, 5, 3, 6, 2, 10, 10, 1, 7, 10, 5, 3, 2, 8, 3, 10, 3, 8, 6, 1, 7, 3, 9, 5, 8, 1, 6, 6, 5, 9, 8, 5, 5, 2, 8, 2, 1, 8, 2, 4, 2, 9, 1, 2, 1, 5, 5, 9, 10, 9, 8, 2, 5, 1, 6, 5, 8, 9, 1, 1, 7, 10, 6, 5, 9, 9, 5, 8, 7, 2, 3, 10, 4, 6, 5, 3, 9, 8, 2, 5, 2, 4, 5, 8, 6, 8, 4, 9, 6, 4, 5, 7, 6, 8, 5, 8, 10, 3, 4, 6, 3, 9, 10, 10, 7, 9, 4, 4, 7, 2, 10, 10, 8, 3, 9, 4, 6, 1, 1, 10, 4, 7, 8, 2, 1, 10, 2, 9, 8, 4, 9, 9, 8, 5, 8, 10, 5, 1, 2, 1, 6, 5, 3, 6, 5, 2, 9, 1, 2, 5, 8, 2, 7, 6, 7, 7, 10, 2, 10, 1, 7, 1, 3, 6, 8, 1, 7, 8, 9, 9, 6, 2, 9, 9, 8, 10, 9, 6, 3, 1, 10, 4, 6, 8, 3, 1, 3, 8, 1, 10, 1, 4, 10, 3, 7, 6, 5, 8, 4, 9, 6, 7, 2, 7, 4, 10, 7, 3, 10, 10, 1, 4, 8, 4, 3, 6, 3, 4, 6, 8, 2, 7, 5, 5, 8, 10, 5, 2, 10, 6, 1, 7, 6, 1, 2, 4, 5, 3, 10, 9, 8, 1, 4, 1, 5, 4, 7, 8, 2, 3, 5, 6, 7, 4, 7, 6, 5, 8, 9, 3, 5, 9, 6, 7, 6, 2, 1, 4, 5, 7, 3, 2, 10, 1, 7, 8, 2, 5, 9, 7, 4, 8, 3, 5, 2, 2, 4, 3, 9, 8, 10, 8, 4, 9, 1, 4, 10, 9, 2, 5, 9, 1, 6, 1, 1, 8, 3, 5, 5, 1, 2, 6, 7, 4, 6, 6, 2, 4, 10, 2, 7, 9, 2, 1, 5, 5, 6, 10, 4, 2, 1, 3, 9, 5, 1, 1, 3, 8, 5, 8, 2, 6, 6, 5, 8, 3, 2, 8, 5, 5, 9, 7, 8, 1, 10, 9, 10, 6, 3, 3, 1, 3, 10, 3, 7, 1, 7, 6, 7, 2, 10, 1, 6, 5, 5, 6, 5, 2, 4, 2, 5, 4, 8, 6, 4, 6, 1, 6, 9, 2, 7, 9, 4, 1, 4, 8, 8, 8, 8, 10, 8, 3, 5, 10, 10, 8, 6, 4, 2, 2, 2, 2, 7, 3, 4, 4, 7, 4, 1, 10, 9, 6, 4, 7, 7, 7, 6, 10, 10, 8, 1, 4, 10, 7, 6, 8, 6, 2, 2, 2, 9, 3, 10, 6, 10, 9, 5, 3, 6, 6, 2, 8, 2, 2, 1, 2, 4, 5, 10, 4, 4, 4, 5, 2, 3, 10, 8, 7, 10, 4, 5, 1, 4, 3, 8, 9, 10, 2, 2, 8, 2, 3, 9, 9, 5, 4, 6, 1, 9, 7, 8, 8, 1, 3, 2, 7, 9, 5, 5, 8, 10, 1, 9, 3, 9, 4, 8, 10, 8, 10, 9, 9, 9, 4, 1, 1, 5, 2, 3, 10, 6, 8, 9, 8, 7, 9, 4, 2, 9, 7, 7, 6, 6, 4, 3, 8, 9, 5, 10, 1, 6, 4, 6, 10, 7, 1, 10, 8, 10, 10, 2, 1, 7, 7, 2, 8, 8, 6, 6, 3, 6, 6, 5, 5, 6, 6, 10, 8, 3, 3, 3, 2, 2, 9, 8, 1, 9, 10, 10, 7, 8, 8, 5, 9, 7, 4, 3, 6, 5, 6, 6, 6, 4, 3, 10, 5, 8, 4, 8, 6, 3, 2, 3, 6, 6, 5, 2, 8, 4, 8, 5, 5, 3, 9, 10, 10, 6, 9, 6, 2, 3, 4, 5, 6, 6, 2, 2, 2, 7, 10, 9, 7, 5, 9, 3, 1, 2, 4, 8, 3, 10, 5, 10, 4, 8, 5, 2, 5, 4, 9, 4, 5, 2, 7, 4, 2, 1, 7, 6, 5, 8, 6, 6, 3, 8, 1, 5, 4, 10, 3, 6, 3, 9, 8, 2, 4, 2, 10, 7, 9, 8, 9, 8, 5, 8, 8, 2, 8, 3, 2, 6, 5, 7, 3, 8, 6, 4, 6, 5, 2, 5, 1, 4, 2, 4, 4, 10, 8, 4, 5, 3, 2, 9, 9, 8, 8, 8, 5, 10, 10, 10, 1, 4, 2, 7, 8, 5, 5, 4, 4, 7, 3, 5, 4, 4, 5, 8, 3, 8, 5, 10, 5, 9, 10, 7, 7, 2, 3, 7, 10, 1, 5, 10, 10, 6, 7, 10, 5, 1, 1, 7, 1, 9, 9, 3, 4, 4, 2, 3, 3, 2, 1, 6, 2, 4, 2, 10, 8, 9, 5, 9, 2, 1, 4, 2, 2, 4, 7, 8, 8, 9, 10, 9, 6, 5, 7, 3, 10, 7, 7, 1, 5, 5, 2, 9, 3, 8, 6, 5, 9, 2, 10, 8, 5, 5, 1, 7, 5, 8, 10, 2, 8, 9, 3, 2, 4, 6, 8, 3, 7, 5, 10, 5, 4, 10, 3, 9, 6, 4, 2, 3, 4, 1, 5, 9, 8, 8, 2, 7, 3, 9, 6, 1, 2, 4, 8, 3, 3, 10, 4, 6, 5, 10, 5, 4, 4, 1, 3, 9, 5, 7, 10, 10, 5, 2, 8, 6, 3, 6, 9, 5, 5, 7, 8, 1, 8, 9, 9, 6, 8, 6, 3, 7, 1, 1, 4, 2, 1, 2, 6, 3, 2, 7, 10, 5, 1, 2, 5, 10, 7, 5, 8, 8, 6, 8, 8, 8, 4, 6, 9, 5, 8, 6, 6, 5, 9, 1, 10, 9, 10, 4, 10, 3, 3, 10, 4, 2, 3, 8, 4, 2, 1, 8, 7, 10, 10, 1, 4, 7, 5, 1, 7, 8, 5, 1, 1, 4, 5, 6, 3, 8, 3, 9, 6, 7, 2, 4, 1, 3, 5, 8, 5, 1, 8, 9, 2, 5, 4, 1, 4, 9, 5, 9, 7, 7, 7, 6, 7, 8, 10, 6, 7, 4, 2, 6, 1, 7, 8, 6, 3, 8, 5, 4, 10, 8, 1, 1, 6, 3, 2, 10, 2, 10, 5, 1, 1, 4, 2, 4, 3, 9, 3, 10, 5, 9, 7, 6, 1, 3, 9, 5, 5, 5, 6, 4, 8, 4, 1, 1, 2, 9, 10, 9, 10, 10, 8, 10, 7, 4, 7, 2, 8, 8, 6, 7, 8, 3, 4, 9, 8, 8, 8, 3, 4, 8, 9, 2, 5, 6, 2, 8, 8, 2, 7, 8, 7, 6, 4, 1, 7, 3, 1, 9, 1, 8, 3, 9, 8, 1, 9, 9, 7, 6, 1, 3, 4, 10, 8, 2, 1, 8, 1, 9, 2, 4, 6, 9, 5, 7, 7, 7, 3, 8, 8, 1, 9, 9, 9, 9, 8, 10, 7, 5, 3, 8, 6, 5, 1, 3, 5, 2, 1, 6, 9, 7, 3, 8, 3, 3, 5, 1, 8, 7, 6, 4, 1, 5, 5, 4, 1, 1, 5, 10, 9, 10, 10, 1, 6, 3, 8, 3, 7, 5, 10, 1, 2, 9, 8, 9, 2, 9, 7, 5, 8, 3, 2, 7, 9, 6, 7, 3, 4, 3, 1, 5, 1, 6, 1, 3, 10, 1, 6, 1, 7, 2, 6, 6, 6, 1, 1, 7, 3, 6, 3, 9, 5, 9, 7, 7, 8, 8, 5, 10, 7, 8, 6, 4, 3, 9, 6, 10, 7, 5, 1, 4, 1, 5, 6, 5, 8, 7, 2, 6, 4, 8, 3, 1, 9, 6, 6, 1, 10, 7, 6, 8, 7, 7, 2, 10, 10, 8, 7, 8, 7, 5, 9, 2, 7, 10, 2, 6, 2, 10, 2, 10, 9, 5, 5, 10, 7, 1, 2, 4, 7, 9, 7, 6, 1, 10, 8, 3, 6, 3, 1, 2, 6, 6, 10, 1, 10, 2, 6, 10, 8, 4, 6, 4, 5, 5, 3, 3, 2, 4, 1, 4, 4, 7, 6, 3, 1, 5, 1, 3, 2, 2, 7, 7, 4, 10, 3, 6, 9, 8, 2, 9, 2, 4, 10, 7, 10, 9, 10, 6, 6, 9, 5, 9, 8, 4, 5, 1, 4, 9, 3, 7, 1, 1, 9, 10, 10, 6, 9, 10, 10, 2, 8, 6, 2, 7, 4, 5, 8, 10, 8, 9, 5, 7, 7, 2, 3, 6, 1, 8, 2, 1, 1, 2, 5, 6, 5, 9, 7, 2, 3, 3, 3, 3, 8, 2, 4, 9, 3, 7, 4, 4, 8, 9, 4, 3, 6, 5, 10, 4, 2, 4, 7, 6, 6, 2, 10, 7, 4, 8, 5, 8, 1, 10, 7, 3, 5, 3, 3, 2, 4, 1, 9, 10, 9, 7, 10, 7, 2, 10, 10, 1, 5, 8, 2, 7, 8, 3, 7, 9, 3, 6, 3, 8, 3, 9, 7, 10, 3, 1, 5, 4, 3, 3, 7, 10, 1, 9, 7, 3, 4, 3, 5, 7, 1, 1, 8, 1, 3, 2, 2, 1, 6, 7, 5, 2, 10, 6, 3, 3, 10, 9, 1, 2, 10, 5, 5, 10, 2, 7, 5, 4, 8, 10, 5, 6, 4, 5, 3, 3, 3, 4, 8, 5, 9, 6, 1, 8, 8, 8, 3, 3, 3, 6, 10, 9, 4, 7, 7, 5, 8, 4, 7, 3, 6, 3, 6, 2, 10, 1, 7, 1, 1, 9, 6, 1, 5, 1, 1, 7, 6, 2, 2, 10, 5, 10, 6, 4, 4, 9, 1, 4, 10, 7, 8, 8, 9, 5, 9, 4, 6, 3, 5, 8, 2, 1, 7, 6, 5, 5, 9, 9, 1, 3, 5, 10, 10, 5, 7, 9, 8, 6, 8, 4, 7, 3, 10, 9, 4, 6, 3, 9, 9, 7, 8, 2, 10, 9, 2, 4, 1, 7, 1, 8, 1, 5, 8, 8, 7, 6, 2, 4, 10, 8, 7, 4, 3, 3, 1, 1, 7, 5, 10, 8, 3, 7, 4, 1, 6, 2, 10, 10, 5, 6, 2, 9, 10, 10, 3, 7, 8, 2, 3, 6, 9, 4, 1, 3, 3, 6, 4, 4, 10, 3, 1, 9, 6, 7, 9, 8, 3, 6, 10, 5, 10, 7, 4, 3, 7, 4, 1, 3, 7, 9, 8, 1, 8, 8, 9, 10, 2, 3, 9, 3, 7, 4, 1, 4, 3, 3, 4, 10, 4, 1, 4, 9, 3, 7, 4, 8, 8, 6, 9, 8, 8, 7, 3, 6, 1, 4, 10, 1, 4, 10, 4, 3, 4, 2, 2, 6, 8, 4, 8, 5, 8, 10, 10, 10, 1, 6, 2, 7, 1, 1, 7, 3, 5, 1, 4, 10, 10, 8, 5, 1, 1, 6, 1, 4, 1, 2, 6, 3, 2, 8, 5, 5, 2, 4, 3, 5, 3, 5, 4, 1, 10, 5, 3, 5, 6, 8, 3, 9, 10, 10, 10, 6, 6, 1, 10, 8, 1, 9, 7, 6, 4, 1, 4, 3, 8, 5, 1, 9, 8, 5, 1, 6, 9, 2, 6, 4, 8, 4, 7, 1, 8, 10, 10, 6, 9, 3, 1, 2, 8, 7, 2, 1, 9, 2, 1, 4, 3, 7, 1, 10, 9, 4, 6, 4, 8, 1, 1, 8, 9, 3, 4, 8, 6, 5, 7, 2, 8, 9, 7, 5, 2, 10, 6, 4, 10, 10, 4, 2, 7, 1, 2, 10, 10, 6, 10, 5, 10, 3, 8, 10, 9, 2, 1, 7, 2, 9, 7, 3, 1, 8, 1, 1, 8, 2, 10, 9, 4, 9, 10, 6, 5, 8, 10, 6, 7, 4, 7, 4, 7, 8, 9, 3, 5, 9, 3, 5, 3, 5, 5, 7, 10, 8, 9, 2, 7, 10, 10, 8, 2, 2, 8, 10, 1, 4, 5, 10, 5, 8, 3, 2, 10, 1, 7, 9, 10, 2, 10, 7, 10, 9, 2, 7, 1, 7, 7, 1, 7, 9, 6, 1, 6, 7, 6, 6, 5, 9, 4, 2, 7, 8, 10, 7, 2, 4, 5, 10, 2, 9, 4, 5, 1, 5, 8, 1, 5, 8, 4, 1, 4, 6, 3, 3, 10, 2, 2, 5, 7, 10, 10, 4, 1, 6, 9, 6, 7, 5, 7, 9, 2, 4, 1, 1, 8, 5, 10, 5, 2, 6, 7, 6, 3, 7, 5, 10, 5, 5, 3, 2, 1, 2, 5, 8, 10, 6, 1, 7, 1, 7, 7, 3, 8, 7, 2, 10, 10, 1, 10, 1, 1, 1, 6, 4, 5, 2, 9, 5, 4, 6, 4, 9, 9, 9, 5, 2, 8, 8, 8, 2, 5, 9, 7, 8, 2, 3, 2, 10, 5, 9, 10, 3, 5, 9, 1, 6, 2, 4, 3, 4, 1, 9, 8, 4, 2, 1, 2, 1, 9, 1, 9, 5
	};
	// ANS: 13,365,787,544,747,134

	auto start = chrono::high_resolution_clock::now();
	//auto tableSet = tableBuilder(sampleSpecial01);
	auto tableSet = tableBuilder(sampleSpecial02);

	auto pairSetMap = get<0>(tableSet);
	auto elementTable = get<1>(tableSet);
	auto lookUpTable = get<2>(tableSet);

	cout << numSquareCombination(pairSetMap, elementTable, lookUpTable) << endl;
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << duration.count() << endl;

	delete lookUpTable;

	return 0;
}

inline specialINT factorial(specialINT  inputInteger) {
	specialINT tempResult = 1;
	specialINT counter = 1;

	while (counter <= inputInteger) {
		tempResult *= counter;
		counter++;
	}
	return tempResult;
}

inline specialINT nCr(specialINT  numSet, int lenSubSet) {
	if (numSet == lenSubSet) {
		return 1;
	}
	else {
		specialINT tempVal = 1;
		specialINT tracker = numSet;
		specialINT lowerBound = numSet - lenSubSet;

		while (tracker > lowerBound) {
			tempVal *= tracker;
			tracker--;
		}

		return tempVal / factorial(lenSubSet);
	}
}


specialINT tripleSet_Normal(map<int, vector<pair<int, int>>>& pairMAP, set<int>& elementTable, int* lookupTable, int targetX) {
	specialINT possibleTupleSet_Normal = 0;
	int boundFirstEle = targetX / 3;
	for (auto firstEle : elementTable) {
		if (firstEle >= boundFirstEle) {
			break;
		}

		int targetPair = targetX - firstEle;
		auto posPairSet = pairMAP.find(targetPair);
		specialINT pairPart = 0;
		if (posPairSet != pairMAP.cend()) {
			for (auto nCrPairSet : posPairSet->second) {
				if (nCrPairSet.first > firstEle) {
					pairPart += nCrPairSet.second;
				}
			}
		}
		possibleTupleSet_Normal += nCr(lookupTable[firstEle], 1) * pairPart;
	}
	return possibleTupleSet_Normal;
}

specialINT tripleSet_Special(set<int>& elementTable, int* lookupTable, int targetX) {
	specialINT possibleTupleSet_Special = 0;
	int specialBound = targetX % 2 != 0 ? targetX / 2 : targetX / 2 - 1;

	for (auto checkSpecial : elementTable) {
		if (checkSpecial > specialBound) {
			break;
		}
		else {
			if (lookupTable[checkSpecial] >= 3 && checkSpecial * 3 == targetX) {
				possibleTupleSet_Special += nCr(lookupTable[checkSpecial], 3);
			}
			if (lookupTable[checkSpecial] >= 2) {
				int nextTarget = targetX - 2 * checkSpecial;
				if (nextTarget != checkSpecial && lookupTable[nextTarget] != 0) {
					possibleTupleSet_Special += nCr(lookupTable[checkSpecial], 2) * nCr(lookupTable[nextTarget], 1);
				}
			}
		}
	}
	return possibleTupleSet_Special;
}

specialINT pairSet_Normal(set<int>& elementTable, int* lookupTable, int targetX) {
	int boundPair = targetX / 2;
	vector<specialINT> pairSetTable;
	for (auto checkNormal : elementTable) {
		if (checkNormal > boundPair) {
			break;
		}

		int targetEle = targetX - checkNormal;
		if (lookupTable[targetEle] != 0) {
			if (targetEle == checkNormal && lookupTable[checkNormal] > 1) {
				pairSetTable.push_back(nCr(lookupTable[checkNormal], 2));
			}
			else if (targetEle != checkNormal && lookupTable[checkNormal] > 0) {
				pairSetTable.push_back(nCr(lookupTable[checkNormal], 1) * nCr(lookupTable[targetEle], 1));
			}
		}
	}

	specialINT possiblePairSet_Normal = 0;
	for (int i = 0; i < pairSetTable.size(); i++) {
		for (int j = i + 1; j < pairSetTable.size(); j++) {
			possiblePairSet_Normal += pairSetTable[i] * pairSetTable[j];
		}
	}
	return possiblePairSet_Normal;
}

specialINT pairSet_Special(set<int>& elementTable, int* lookupTable, int targetX) {

	specialINT possiblePairSet_Special = 0;
	int boundSpecial = targetX % 2 != 0 ? targetX / 2 + 1 : targetX / 2;
	for (auto checkSpecial : elementTable) {
		if (checkSpecial > boundSpecial) {
			break;
		}
		else if (checkSpecial == boundSpecial) {
			if (targetX % 2 == 0 && lookupTable[checkSpecial] >= 4 && 2 * checkSpecial == targetX) {
				possiblePairSet_Special += nCr(lookupTable[checkSpecial], 4);
			}
		}
		else {
			if (targetX != 2 * checkSpecial && lookupTable[checkSpecial] >= 2 && lookupTable[targetX - checkSpecial] >= 2) {
				possiblePairSet_Special += nCr(lookupTable[checkSpecial], 2) * nCr(lookupTable[targetX - checkSpecial], 2);
			}
		}
	}
	return possiblePairSet_Special;
}



inline specialINT tripleSet(map<int, vector<pair<int, int>>>& pairMAP, set<int>& elementTable, int* lookupTable, int targetX) {
	return nCr(lookupTable[targetX], 3)
		* (tripleSet_Normal(pairMAP, elementTable, lookupTable, targetX) + tripleSet_Special(elementTable, lookupTable, targetX));
}

inline specialINT pairSet(set<int>& elementTable, int* lookupTable, int targetX) {
	return nCr(lookupTable[targetX], 2)
		* (pairSet_Normal(elementTable, lookupTable, targetX) + pairSet_Special(elementTable, lookupTable, targetX));
}



tuple<map<int, vector<pair<int, int>>>, set<int>, int*> tableBuilder(const vector<int>& inputVector) {
	int sizeArray = *max_element(inputVector.begin(), inputVector.end()) + 1;

	int* lookupTalbeP = new int[sizeArray]();
	set<int> elementListTable;
	for (auto buildElementTable : inputVector) {
		lookupTalbeP[buildElementTable]++;
		elementListTable.insert(buildElementTable);
	}

	int maxTarget = 0;
	for (auto findMaxTarget : elementListTable) {
		if (lookupTalbeP[findMaxTarget] > 1 && findMaxTarget > maxTarget) {
			maxTarget = findMaxTarget;
		}
	}

	map<int, vector<pair<int, int>>> pairSetMap;
	int pairSumLimit = maxTarget - *elementListTable.cbegin();
	for (auto firstEle = elementListTable.cbegin(); firstEle != elementListTable.cend() && *firstEle <= pairSumLimit; firstEle++) {
		auto lowerBound = firstEle;
		lowerBound++;

		int firstElement = *firstEle;
		int nCrFirstEle = nCr(lookupTalbeP[firstElement], 1);

		for (auto secondEle = lowerBound; secondEle != elementListTable.cend() && *firstEle + *secondEle <= pairSumLimit; secondEle++) {
			pairSetMap[firstElement + *secondEle].push_back(make_pair(firstElement, nCrFirstEle * nCr(lookupTalbeP[*secondEle], 1)));
		}
	}

	return make_tuple(pairSetMap, elementListTable, lookupTalbeP);
}

specialINT numSquareCombination(map<int, vector<pair<int, int>>>& pairMAP, set<int>& elementList, int* lookupTable) {
	specialINT numTriple = 0;
	specialINT numPair = 0;

	for (auto targetVal : elementList) {
		if (lookupTable[targetVal] >= 3) {
			numTriple += tripleSet(pairMAP, elementList, lookupTable, targetVal);
		}
		if (lookupTable[targetVal] >= 2) {
			numPair += pairSet(elementList, lookupTable, targetVal);
		}
	}
	return numTriple + numPair;
}