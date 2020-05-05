# Interpolazione polinomiale

## Polyfit

Supponiamo di aver definito due vettori xdata e ydata entrambi di lunghezza n+1. Il comando polyfit

```matlab
P = polyfit(xdata, ydata, n);
```

restituisce il vettore (di lunghezza n + 1) dei coefficienti del polinomio interpolante i nostri dati.

I coefficienti sono ordinati per potenze decrescenti della x ossia

<div style='text-align: center;'>P(1) = an; P(2) = an−1; ...; P(n + 1) = a0.</div>

## Polyval

Possiamo quindi valutare il polinomio dato un generico vettore x usando il comando polyval

```matlab
P = polyfit(xdata, ydata, n);
x = linspace(0, 10);
yfit = polyval(P, x);
```

# Interpolazione polinomiale a tratti

## Interp1

Per ogni coppia di punti (xi, yi) e (xi+1, yi+1) voglio trovare il polinomio pj (x) di grado m 

<div style='text-align: center;'>pj(x) = a0 + a1x + a2x^2 + ... + amx^m
</div>


che interpoli a due a due le coppie di dati.

Se voglio usare l’interpolazione a tratti posso usare il comando interp1

```matlab
ypl = interp1(xdata, ydata, x);
```

Così facendo stiamo solamente richiedendo che la funzione interpolante sia continua, le sue derivate saranno discontinue.

## Spline

Se vogliamo richiedere anche continuità nelle derivate tra un intervallo e il seguente, possiamo usare le Splines.
Matlab ha la funzione spline che utilizza di default polinomi di terzo grado continui e che abbiano derivata continua tra un intervallo e l’altro.

```matlab
yspline = spline(xdata , ydata , x);
```



