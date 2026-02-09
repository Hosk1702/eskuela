var time: Int = 3665;

var hours: Int = time / 3600;
var minutes: Int = (time%3600) / 60;
var seconds: Int = time% 60;
print(hours,":",minutes,":",seconds);
