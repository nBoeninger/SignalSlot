# Signal Slots

Im folgenden soll das Signal Slot "Pattern" implementiert werden.
Generell ist dabei folgende Idee:

Ein Signal kann etwas emitten. Jeder darauf verbundene Slot wird anschließend darüber informiert und erhält das Signal.
So wird ein Signal als int deklariert, auf das Signal wird ein Slot gehängt.
Wird die emit funktion des Signals aufgerufen, wird der auf das Signal gelegte Slot ausgeführt. 
Dabei könnte das ganze folgendermassen aussehen.
Ein Signal ist unter anderem eine Verkette Liste, welche Slots als Datentypen abelegt. Sobald das Signal emittede wird, werden jede Slots aus der Liste geholt, und mit dem typen des Signals ausgeführt. Ein Slot muss daher als ersten Funktionsparameter denselben Typen erwarten wie das Signal.
Der Slot ist daher eigentlich nur ein Wrapper um einen Funktionspointer.

# Disconnect Slots 
Um Slots aus der verketteten Liste zu entfernen müssen wir zunächst verifizieren ob es sich um den Slot handelt den wir auch entfernen möchten. Das machen wir indem wir die Speicheradresse der Funktion nehmen. Da diese im Prozess Kontext einzigartig ist, sollte das im ersten Schritt auch als ID ausreichen.
Entfernen der Elements aus der Liste erfolgt anschließend indem wir zunächst die besagte Funktion finden. Anschließend haben wir einen pos pointer welcher auf diese Stelle zeigt, und einen Pointer welcher auf die vorherige Stelle zeigt. Wir ordnen nun also dem prev_nxt die Adresses der curr_nxt zu. 

# Testing
Das ganze sollte nun mit unit test und einer statischen Codeanalyse versehen werden. Dabei wird zunächst ein Unit Testing Framework ausgewählt.
