## a)

## b)

## c)

## d)
Formel:
> Übergebenens Jahr: $j$
> 
> Übergebener Monat: $m$
>
> Übergebener Tag: $D$
>
> Übergebene Stunde: $h$
>
> Übergebene Minute: $M$
>
> Übergebene Sekunde: $s$
> 
> Tage seit Jahresanfang: $d_j$
>
> Tag-Schaltjahrkorrektur übergebenes Jahr: $d_l$
> Wenn $j$ ein Schaltjahr ist, dann setze $d_l=1$, ansonsten setze $d_l=0$
> 
> Anzahl vergangener Schaltjahre: $U_l = (j-1970)/4-(j-1900)/100-(j-1600)/400$
> 
> Tage seit 1970: $U_d = (j-1970)*365 + U_l + d_j + d_l$
>
> Stunden seit Unix-Start: $U_H = U_d * 24 + h$
>
> Minuten seit Unix-Start: $U_M = U_H * 60 + M$
>
> Sekunden seit Unix-Start: $U_s = U_M * 60 + s$

## e)

## f)

## g)