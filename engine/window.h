#ifndef WINDOW_H
#define WINDOW_H

#define WINDOW_SIZE 1024

/** WINDOW LOOKUP TABLE **/
static float WINDOW[WINDOW_SIZE] = {
    0.0,
    0.00195694716243,
    0.00391389432485,
    0.00587084148728,
    0.00782778864971,
    0.00978473581213,
    0.0117416829746,
    0.013698630137,
    0.0156555772994,
    0.0176125244618,
    0.0195694716243,
    0.0215264187867,
    0.0234833659491,
    0.0254403131115,
    0.027397260274,
    0.0293542074364,
    0.0313111545988,
    0.0332681017613,
    0.0352250489237,
    0.0371819960861,
    0.0391389432485,
    0.041095890411,
    0.0430528375734,
    0.0450097847358,
    0.0469667318982,
    0.0489236790607,
    0.0508806262231,
    0.0528375733855,
    0.0547945205479,
    0.0567514677104,
    0.0587084148728,
    0.0606653620352,
    0.0626223091977,
    0.0645792563601,
    0.0665362035225,
    0.0684931506849,
    0.0704500978474,
    0.0724070450098,
    0.0743639921722,
    0.0763209393346,
    0.0782778864971,
    0.0802348336595,
    0.0821917808219,
    0.0841487279843,
    0.0861056751468,
    0.0880626223092,
    0.0900195694716,
    0.0919765166341,
    0.0939334637965,
    0.0958904109589,
    0.0978473581213,
    0.0998043052838,
    0.101761252446,
    0.103718199609,
    0.105675146771,
    0.107632093933,
    0.109589041096,
    0.111545988258,
    0.113502935421,
    0.115459882583,
    0.117416829746,
    0.119373776908,
    0.12133072407,
    0.123287671233,
    0.125244618395,
    0.127201565558,
    0.12915851272,
    0.131115459883,
    0.133072407045,
    0.135029354207,
    0.13698630137,
    0.138943248532,
    0.140900195695,
    0.142857142857,
    0.14481409002,
    0.146771037182,
    0.148727984344,
    0.150684931507,
    0.152641878669,
    0.154598825832,
    0.156555772994,
    0.158512720157,
    0.160469667319,
    0.162426614481,
    0.164383561644,
    0.166340508806,
    0.168297455969,
    0.170254403131,
    0.172211350294,
    0.174168297456,
    0.176125244618,
    0.178082191781,
    0.180039138943,
    0.181996086106,
    0.183953033268,
    0.185909980431,
    0.187866927593,
    0.189823874755,
    0.191780821918,
    0.19373776908,
    0.195694716243,
    0.197651663405,
    0.199608610568,
    0.20156555773,
    0.203522504892,
    0.205479452055,
    0.207436399217,
    0.20939334638,
    0.211350293542,
    0.213307240705,
    0.215264187867,
    0.217221135029,
    0.219178082192,
    0.221135029354,
    0.223091976517,
    0.225048923679,
    0.227005870841,
    0.228962818004,
    0.230919765166,
    0.232876712329,
    0.234833659491,
    0.236790606654,
    0.238747553816,
    0.240704500978,
    0.242661448141,
    0.244618395303,
    0.246575342466,
    0.248532289628,
    0.250489236791,
    0.252446183953,
    0.254403131115,
    0.256360078278,
    0.25831702544,
    0.260273972603,
    0.262230919765,
    0.264187866928,
    0.26614481409,
    0.268101761252,
    0.270058708415,
    0.272015655577,
    0.27397260274,
    0.275929549902,
    0.277886497065,
    0.279843444227,
    0.281800391389,
    0.283757338552,
    0.285714285714,
    0.287671232877,
    0.289628180039,
    0.291585127202,
    0.293542074364,
    0.295499021526,
    0.297455968689,
    0.299412915851,
    0.301369863014,
    0.303326810176,
    0.305283757339,
    0.307240704501,
    0.309197651663,
    0.311154598826,
    0.313111545988,
    0.315068493151,
    0.317025440313,
    0.318982387476,
    0.320939334638,
    0.3228962818,
    0.324853228963,
    0.326810176125,
    0.328767123288,
    0.33072407045,
    0.332681017613,
    0.334637964775,
    0.336594911937,
    0.3385518591,
    0.340508806262,
    0.342465753425,
    0.344422700587,
    0.34637964775,
    0.348336594912,
    0.350293542074,
    0.352250489237,
    0.354207436399,
    0.356164383562,
    0.358121330724,
    0.360078277886,
    0.362035225049,
    0.363992172211,
    0.365949119374,
    0.367906066536,
    0.369863013699,
    0.371819960861,
    0.373776908023,
    0.375733855186,
    0.377690802348,
    0.379647749511,
    0.381604696673,
    0.383561643836,
    0.385518590998,
    0.38747553816,
    0.389432485323,
    0.391389432485,
    0.393346379648,
    0.39530332681,
    0.397260273973,
    0.399217221135,
    0.401174168297,
    0.40313111546,
    0.405088062622,
    0.407045009785,
    0.409001956947,
    0.41095890411,
    0.412915851272,
    0.414872798434,
    0.416829745597,
    0.418786692759,
    0.420743639922,
    0.422700587084,
    0.424657534247,
    0.426614481409,
    0.428571428571,
    0.430528375734,
    0.432485322896,
    0.434442270059,
    0.436399217221,
    0.438356164384,
    0.440313111546,
    0.442270058708,
    0.444227005871,
    0.446183953033,
    0.448140900196,
    0.450097847358,
    0.452054794521,
    0.454011741683,
    0.455968688845,
    0.457925636008,
    0.45988258317,
    0.461839530333,
    0.463796477495,
    0.465753424658,
    0.46771037182,
    0.469667318982,
    0.471624266145,
    0.473581213307,
    0.47553816047,
    0.477495107632,
    0.479452054795,
    0.481409001957,
    0.483365949119,
    0.485322896282,
    0.487279843444,
    0.489236790607,
    0.491193737769,
    0.493150684932,
    0.495107632094,
    0.497064579256,
    0.499021526419,
    0.500978473581,
    0.502935420744,
    0.504892367906,
    0.506849315068,
    0.508806262231,
    0.510763209393,
    0.512720156556,
    0.514677103718,
    0.516634050881,
    0.518590998043,
    0.520547945205,
    0.522504892368,
    0.52446183953,
    0.526418786693,
    0.528375733855,
    0.530332681018,
    0.53228962818,
    0.534246575342,
    0.536203522505,
    0.538160469667,
    0.54011741683,
    0.542074363992,
    0.544031311155,
    0.545988258317,
    0.547945205479,
    0.549902152642,
    0.551859099804,
    0.553816046967,
    0.555772994129,
    0.557729941292,
    0.559686888454,
    0.561643835616,
    0.563600782779,
    0.565557729941,
    0.567514677104,
    0.569471624266,
    0.571428571429,
    0.573385518591,
    0.575342465753,
    0.577299412916,
    0.579256360078,
    0.581213307241,
    0.583170254403,
    0.585127201566,
    0.587084148728,
    0.58904109589,
    0.590998043053,
    0.592954990215,
    0.594911937378,
    0.59686888454,
    0.598825831703,
    0.600782778865,
    0.602739726027,
    0.60469667319,
    0.606653620352,
    0.608610567515,
    0.610567514677,
    0.61252446184,
    0.614481409002,
    0.616438356164,
    0.618395303327,
    0.620352250489,
    0.622309197652,
    0.624266144814,
    0.626223091977,
    0.628180039139,
    0.630136986301,
    0.632093933464,
    0.634050880626,
    0.636007827789,
    0.637964774951,
    0.639921722114,
    0.641878669276,
    0.643835616438,
    0.645792563601,
    0.647749510763,
    0.649706457926,
    0.651663405088,
    0.65362035225,
    0.655577299413,
    0.657534246575,
    0.659491193738,
    0.6614481409,
    0.663405088063,
    0.665362035225,
    0.667318982387,
    0.66927592955,
    0.671232876712,
    0.673189823875,
    0.675146771037,
    0.6771037182,
    0.679060665362,
    0.681017612524,
    0.682974559687,
    0.684931506849,
    0.686888454012,
    0.688845401174,
    0.690802348337,
    0.692759295499,
    0.694716242661,
    0.696673189824,
    0.698630136986,
    0.700587084149,
    0.702544031311,
    0.704500978474,
    0.706457925636,
    0.708414872798,
    0.710371819961,
    0.712328767123,
    0.714285714286,
    0.716242661448,
    0.718199608611,
    0.720156555773,
    0.722113502935,
    0.724070450098,
    0.72602739726,
    0.727984344423,
    0.729941291585,
    0.731898238748,
    0.73385518591,
    0.735812133072,
    0.737769080235,
    0.739726027397,
    0.74168297456,
    0.743639921722,
    0.745596868885,
    0.747553816047,
    0.749510763209,
    0.751467710372,
    0.753424657534,
    0.755381604697,
    0.757338551859,
    0.759295499022,
    0.761252446184,
    0.763209393346,
    0.765166340509,
    0.767123287671,
    0.769080234834,
    0.771037181996,
    0.772994129159,
    0.774951076321,
    0.776908023483,
    0.778864970646,
    0.780821917808,
    0.782778864971,
    0.784735812133,
    0.786692759295,
    0.788649706458,
    0.79060665362,
    0.792563600783,
    0.794520547945,
    0.796477495108,
    0.79843444227,
    0.800391389432,
    0.802348336595,
    0.804305283757,
    0.80626223092,
    0.808219178082,
    0.810176125245,
    0.812133072407,
    0.814090019569,
    0.816046966732,
    0.818003913894,
    0.819960861057,
    0.821917808219,
    0.823874755382,
    0.825831702544,
    0.827788649706,
    0.829745596869,
    0.831702544031,
    0.833659491194,
    0.835616438356,
    0.837573385519,
    0.839530332681,
    0.841487279843,
    0.843444227006,
    0.845401174168,
    0.847358121331,
    0.849315068493,
    0.851272015656,
    0.853228962818,
    0.85518590998,
    0.857142857143,
    0.859099804305,
    0.861056751468,
    0.86301369863,
    0.864970645793,
    0.866927592955,
    0.868884540117,
    0.87084148728,
    0.872798434442,
    0.874755381605,
    0.876712328767,
    0.87866927593,
    0.880626223092,
    0.882583170254,
    0.884540117417,
    0.886497064579,
    0.888454011742,
    0.890410958904,
    0.892367906067,
    0.894324853229,
    0.896281800391,
    0.898238747554,
    0.900195694716,
    0.902152641879,
    0.904109589041,
    0.906066536204,
    0.908023483366,
    0.909980430528,
    0.911937377691,
    0.913894324853,
    0.915851272016,
    0.917808219178,
    0.919765166341,
    0.921722113503,
    0.923679060665,
    0.925636007828,
    0.92759295499,
    0.929549902153,
    0.931506849315,
    0.933463796477,
    0.93542074364,
    0.937377690802,
    0.939334637965,
    0.941291585127,
    0.94324853229,
    0.945205479452,
    0.947162426614,
    0.949119373777,
    0.951076320939,
    0.953033268102,
    0.954990215264,
    0.956947162427,
    0.958904109589,
    0.960861056751,
    0.962818003914,
    0.964774951076,
    0.966731898239,
    0.968688845401,
    0.970645792564,
    0.972602739726,
    0.974559686888,
    0.976516634051,
    0.978473581213,
    0.980430528376,
    0.982387475538,
    0.984344422701,
    0.986301369863,
    0.988258317025,
    0.990215264188,
    0.99217221135,
    0.994129158513,
    0.996086105675,
    0.998043052838,
    1.0,
    1.0,
    0.998043052838,
    0.996086105675,
    0.994129158513,
    0.99217221135,
    0.990215264188,
    0.988258317025,
    0.986301369863,
    0.984344422701,
    0.982387475538,
    0.980430528376,
    0.978473581213,
    0.976516634051,
    0.974559686888,
    0.972602739726,
    0.970645792564,
    0.968688845401,
    0.966731898239,
    0.964774951076,
    0.962818003914,
    0.960861056751,
    0.958904109589,
    0.956947162427,
    0.954990215264,
    0.953033268102,
    0.951076320939,
    0.949119373777,
    0.947162426614,
    0.945205479452,
    0.94324853229,
    0.941291585127,
    0.939334637965,
    0.937377690802,
    0.93542074364,
    0.933463796477,
    0.931506849315,
    0.929549902153,
    0.92759295499,
    0.925636007828,
    0.923679060665,
    0.921722113503,
    0.919765166341,
    0.917808219178,
    0.915851272016,
    0.913894324853,
    0.911937377691,
    0.909980430528,
    0.908023483366,
    0.906066536204,
    0.904109589041,
    0.902152641879,
    0.900195694716,
    0.898238747554,
    0.896281800391,
    0.894324853229,
    0.892367906067,
    0.890410958904,
    0.888454011742,
    0.886497064579,
    0.884540117417,
    0.882583170254,
    0.880626223092,
    0.87866927593,
    0.876712328767,
    0.874755381605,
    0.872798434442,
    0.87084148728,
    0.868884540117,
    0.866927592955,
    0.864970645793,
    0.86301369863,
    0.861056751468,
    0.859099804305,
    0.857142857143,
    0.85518590998,
    0.853228962818,
    0.851272015656,
    0.849315068493,
    0.847358121331,
    0.845401174168,
    0.843444227006,
    0.841487279843,
    0.839530332681,
    0.837573385519,
    0.835616438356,
    0.833659491194,
    0.831702544031,
    0.829745596869,
    0.827788649706,
    0.825831702544,
    0.823874755382,
    0.821917808219,
    0.819960861057,
    0.818003913894,
    0.816046966732,
    0.814090019569,
    0.812133072407,
    0.810176125245,
    0.808219178082,
    0.80626223092,
    0.804305283757,
    0.802348336595,
    0.800391389432,
    0.79843444227,
    0.796477495108,
    0.794520547945,
    0.792563600783,
    0.79060665362,
    0.788649706458,
    0.786692759295,
    0.784735812133,
    0.782778864971,
    0.780821917808,
    0.778864970646,
    0.776908023483,
    0.774951076321,
    0.772994129159,
    0.771037181996,
    0.769080234834,
    0.767123287671,
    0.765166340509,
    0.763209393346,
    0.761252446184,
    0.759295499022,
    0.757338551859,
    0.755381604697,
    0.753424657534,
    0.751467710372,
    0.749510763209,
    0.747553816047,
    0.745596868885,
    0.743639921722,
    0.74168297456,
    0.739726027397,
    0.737769080235,
    0.735812133072,
    0.73385518591,
    0.731898238748,
    0.729941291585,
    0.727984344423,
    0.72602739726,
    0.724070450098,
    0.722113502935,
    0.720156555773,
    0.718199608611,
    0.716242661448,
    0.714285714286,
    0.712328767123,
    0.710371819961,
    0.708414872798,
    0.706457925636,
    0.704500978474,
    0.702544031311,
    0.700587084149,
    0.698630136986,
    0.696673189824,
    0.694716242661,
    0.692759295499,
    0.690802348337,
    0.688845401174,
    0.686888454012,
    0.684931506849,
    0.682974559687,
    0.681017612524,
    0.679060665362,
    0.6771037182,
    0.675146771037,
    0.673189823875,
    0.671232876712,
    0.66927592955,
    0.667318982387,
    0.665362035225,
    0.663405088063,
    0.6614481409,
    0.659491193738,
    0.657534246575,
    0.655577299413,
    0.65362035225,
    0.651663405088,
    0.649706457926,
    0.647749510763,
    0.645792563601,
    0.643835616438,
    0.641878669276,
    0.639921722114,
    0.637964774951,
    0.636007827789,
    0.634050880626,
    0.632093933464,
    0.630136986301,
    0.628180039139,
    0.626223091977,
    0.624266144814,
    0.622309197652,
    0.620352250489,
    0.618395303327,
    0.616438356164,
    0.614481409002,
    0.61252446184,
    0.610567514677,
    0.608610567515,
    0.606653620352,
    0.60469667319,
    0.602739726027,
    0.600782778865,
    0.598825831703,
    0.59686888454,
    0.594911937378,
    0.592954990215,
    0.590998043053,
    0.58904109589,
    0.587084148728,
    0.585127201566,
    0.583170254403,
    0.581213307241,
    0.579256360078,
    0.577299412916,
    0.575342465753,
    0.573385518591,
    0.571428571429,
    0.569471624266,
    0.567514677104,
    0.565557729941,
    0.563600782779,
    0.561643835616,
    0.559686888454,
    0.557729941292,
    0.555772994129,
    0.553816046967,
    0.551859099804,
    0.549902152642,
    0.547945205479,
    0.545988258317,
    0.544031311155,
    0.542074363992,
    0.54011741683,
    0.538160469667,
    0.536203522505,
    0.534246575342,
    0.53228962818,
    0.530332681018,
    0.528375733855,
    0.526418786693,
    0.52446183953,
    0.522504892368,
    0.520547945205,
    0.518590998043,
    0.516634050881,
    0.514677103718,
    0.512720156556,
    0.510763209393,
    0.508806262231,
    0.506849315068,
    0.504892367906,
    0.502935420744,
    0.500978473581,
    0.499021526419,
    0.497064579256,
    0.495107632094,
    0.493150684932,
    0.491193737769,
    0.489236790607,
    0.487279843444,
    0.485322896282,
    0.483365949119,
    0.481409001957,
    0.479452054795,
    0.477495107632,
    0.47553816047,
    0.473581213307,
    0.471624266145,
    0.469667318982,
    0.46771037182,
    0.465753424658,
    0.463796477495,
    0.461839530333,
    0.45988258317,
    0.457925636008,
    0.455968688845,
    0.454011741683,
    0.452054794521,
    0.450097847358,
    0.448140900196,
    0.446183953033,
    0.444227005871,
    0.442270058708,
    0.440313111546,
    0.438356164384,
    0.436399217221,
    0.434442270059,
    0.432485322896,
    0.430528375734,
    0.428571428571,
    0.426614481409,
    0.424657534247,
    0.422700587084,
    0.420743639922,
    0.418786692759,
    0.416829745597,
    0.414872798434,
    0.412915851272,
    0.41095890411,
    0.409001956947,
    0.407045009785,
    0.405088062622,
    0.40313111546,
    0.401174168297,
    0.399217221135,
    0.397260273973,
    0.39530332681,
    0.393346379648,
    0.391389432485,
    0.389432485323,
    0.38747553816,
    0.385518590998,
    0.383561643836,
    0.381604696673,
    0.379647749511,
    0.377690802348,
    0.375733855186,
    0.373776908023,
    0.371819960861,
    0.369863013699,
    0.367906066536,
    0.365949119374,
    0.363992172211,
    0.362035225049,
    0.360078277886,
    0.358121330724,
    0.356164383562,
    0.354207436399,
    0.352250489237,
    0.350293542074,
    0.348336594912,
    0.34637964775,
    0.344422700587,
    0.342465753425,
    0.340508806262,
    0.3385518591,
    0.336594911937,
    0.334637964775,
    0.332681017613,
    0.33072407045,
    0.328767123288,
    0.326810176125,
    0.324853228963,
    0.3228962818,
    0.320939334638,
    0.318982387476,
    0.317025440313,
    0.315068493151,
    0.313111545988,
    0.311154598826,
    0.309197651663,
    0.307240704501,
    0.305283757339,
    0.303326810176,
    0.301369863014,
    0.299412915851,
    0.297455968689,
    0.295499021526,
    0.293542074364,
    0.291585127202,
    0.289628180039,
    0.287671232877,
    0.285714285714,
    0.283757338552,
    0.281800391389,
    0.279843444227,
    0.277886497065,
    0.275929549902,
    0.27397260274,
    0.272015655577,
    0.270058708415,
    0.268101761252,
    0.26614481409,
    0.264187866928,
    0.262230919765,
    0.260273972603,
    0.25831702544,
    0.256360078278,
    0.254403131115,
    0.252446183953,
    0.250489236791,
    0.248532289628,
    0.246575342466,
    0.244618395303,
    0.242661448141,
    0.240704500978,
    0.238747553816,
    0.236790606654,
    0.234833659491,
    0.232876712329,
    0.230919765166,
    0.228962818004,
    0.227005870841,
    0.225048923679,
    0.223091976517,
    0.221135029354,
    0.219178082192,
    0.217221135029,
    0.215264187867,
    0.213307240705,
    0.211350293542,
    0.20939334638,
    0.207436399217,
    0.205479452055,
    0.203522504892,
    0.20156555773,
    0.199608610568,
    0.197651663405,
    0.195694716243,
    0.19373776908,
    0.191780821918,
    0.189823874755,
    0.187866927593,
    0.185909980431,
    0.183953033268,
    0.181996086106,
    0.180039138943,
    0.178082191781,
    0.176125244618,
    0.174168297456,
    0.172211350294,
    0.170254403131,
    0.168297455969,
    0.166340508806,
    0.164383561644,
    0.162426614481,
    0.160469667319,
    0.158512720157,
    0.156555772994,
    0.154598825832,
    0.152641878669,
    0.150684931507,
    0.148727984344,
    0.146771037182,
    0.14481409002,
    0.142857142857,
    0.140900195695,
    0.138943248532,
    0.13698630137,
    0.135029354207,
    0.133072407045,
    0.131115459883,
    0.12915851272,
    0.127201565558,
    0.125244618395,
    0.123287671233,
    0.12133072407,
    0.119373776908,
    0.117416829746,
    0.115459882583,
    0.113502935421,
    0.111545988258,
    0.109589041096,
    0.107632093933,
    0.105675146771,
    0.103718199609,
    0.101761252446,
    0.0998043052838,
    0.0978473581213,
    0.0958904109589,
    0.0939334637965,
    0.0919765166341,
    0.0900195694716,
    0.0880626223092,
    0.0861056751468,
    0.0841487279843,
    0.0821917808219,
    0.0802348336595,
    0.0782778864971,
    0.0763209393346,
    0.0743639921722,
    0.0724070450098,
    0.0704500978474,
    0.0684931506849,
    0.0665362035225,
    0.0645792563601,
    0.0626223091977,
    0.0606653620352,
    0.0587084148728,
    0.0567514677104,
    0.0547945205479,
    0.0528375733855,
    0.0508806262231,
    0.0489236790607,
    0.0469667318982,
    0.0450097847358,
    0.0430528375734,
    0.041095890411,
    0.0391389432485,
    0.0371819960861,
    0.0352250489237,
    0.0332681017613,
    0.0313111545988,
    0.0293542074364,
    0.027397260274,
    0.0254403131115,
    0.0234833659491,
    0.0215264187867,
    0.0195694716243,
    0.0176125244618,
    0.0156555772994,
    0.013698630137,
    0.0117416829746,
    0.00978473581213,
    0.00782778864971,
    0.00587084148728,
    0.00391389432485,
    0.00195694716243,
    0.0
};
#endif // WINDOW_H