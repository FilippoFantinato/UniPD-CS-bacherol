var xA >=0, <=5 integer;
var xB >=2 integer;

maximize z: 3*xA + 6*xB;

s.t. disp: xA + 2*xB <= 10;
s.t. navigazione: xA <= 9;
s.t. tastiera: 2*xA + 3*xB <= 21;
s.t. logica: xA + 2*xB <= 18;
s.t. trasmissione: xA + 3*xB <= 12;
s.t. led: xA <= 10;
