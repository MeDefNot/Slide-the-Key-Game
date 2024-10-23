**Slide the Key Game**

**CONCEPT**
There is a 6x6 grid which contains a key along with some horizontal and vertical slabs/elements/blocks. Your task is to slide it across the grid from either left to right(If the key is horizontal) or top to bottom (If the key is vertical)

**Preparing the grid**(skip this if you're interested in playing sample games. Go to *"HOW TO PLAY* section" :3)<br>
First you are greeted with the 6x6 grid.
<pre>
"
Generating an empty 6x6 grid...
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   |
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   |
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   | 
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   |
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   | 
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   |

"</pre>

Next, you need to place the blocks or elements. The rules are as follows:
* They can have lengths from 2 to 6.
* They be either horizontal or vertical
* They cannot go outside the grid (You figured this much already :P)

Add as many elements as you want. 
Say yes to this.
<pre>
Do you want to add an element?(y/n) :
</pre>
*INPUT*
<pre>y</pre> 
Put your element properties
<pre>
Put your input seperated by spaces in the following order:
length orientation(v/h) left top
</pre>
*INPUT*
<pre>
   3 v 0 0
</pre>
This basically means a vertical element of length 3 will be placed at 0 boxes distance from the left and 0 boxes distance from the top
<pre>
  **$Curret grid$**
          ___ ___ ___ ___ ___ ___
           A |   |   |   |   |   |
          ___ ___ ___ ___ ___ ___
           A |   |   |   |   |   |
          ___ ___ ___ ___ ___ ___
           A |   |   |   |   |   |
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   |
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   | 
          ___ ___ ___ ___ ___ ___
             |   |   |   |   |   |
</pre>
Add as many elements as you want.
<pre>
  **$Curret grid$**
          ___ ___ ___ ___ ___ ___
           A | H | H | C |   | D |
          ___ ___ ___ ___ ___ ___
           A | B |   | C |   | D |
          ___ ___ ___ ___ ___ ___
           A | B |   |   | E | D | 
          ___ ___ ___ ___ ___ ___
           I | I | F | G | E |   |
          ___ ___ ___ ___ ___ ___
             |   | F | G | J | J |
          ___ ___ ___ ___ ___ ___
             | K | K | L | L |   |

</pre>
Next, say no to..
<pre>
  Do you want to add an element?(y/n):
</pre>
<pre>
   n
</pre>
->
<pre>
Place the key in position (x,y).Put your input seperated by spaces in the following order: orientation  x y
</pre>
Input:
<pre>
   h 2 2
</pre>
This will place the key horizontally at a distance of two blocks from the left and two blocks from the top. Note: a key is always 2 blocks in length

<pre>
   ~ FINAL GRID ~
          ___ ___ ___ ___ ___ ___
           A | H | H | C |   | D |
          ___ ___ ___ ___ ___ ___
           A | B |   | C |   | D |
          ___ ___ ___ ___ ___ ___
           A | B | $ | $ | E | D |
          ___ ___ ___ ___ ___ ___
           I | I | F | G | E |   |
          ___ ___ ___ ___ ___ ___
             |   | F | G | J | J |
          ___ ___ ___ ___ ___ ___
             | K | K | L | L |   |
</pre>
**Voala your grid is ready**💃

**HOW TO PLAY**
* Each set of same alphabets represent an "Element"
* The element with the dollar sign ($$) is the key
* Slide the key across. To the right for horizontal keys and down for vertical keys.
* You can move horizontal elements only horizontally. (Element H , $, I , J, K, L in the example)
* You can move vertical elements only vertically
* Elements cannot overlap
* Elements cannot go outside grid
* You win if you can successfully slide the key across. (Didn't code the win message yet. But give yourself a pat if you can 🙃)
<pre>
  Start playing. Give your moves in the format: Element direction(R/L/U/D)
 For example: A D
(This will take block containing element A down if possible)
</pre>
* As each element is represented by the alphabets. The first input has to be a character that represents them
* Use L for Left, R for Right, U for Up and D for Down. This will move the element by one block in that direction if possible
<pre>
Move:
</pre>
Input:
<pre>
  E U
</pre>
This is how the grid looks now:
<pre>
          ___ ___ ___ ___ ___ ___
           A | H | H | C |   | D |
          ___ ___ ___ ___ ___ ___
           A | B |   | C | E | D |
          ___ ___ ___ ___ ___ ___
           A | B | $ | $ | E | D |
          ___ ___ ___ ___ ___ ___
           I | I | F | G |   |   |
          ___ ___ ___ ___ ___ ___
             |   | F | G | J | J |
          ___ ___ ___ ___ ___ ___
             | K | K | L | L |   |

</pre>

*Go to the sample.txt file for sample questions* <br>
**✨Happy Playing✨**
**
