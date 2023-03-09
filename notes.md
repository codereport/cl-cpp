```
S: \abc.ac(bc)
K: \ab.a

   FA      Combinator Spelling
   ==      ===================
I: \a.a -> SKKx
            abc         1) map "abc" ... SKIBW (xyz)*
            ac(bc)      2a) lookup our pattern (S)
            Kx(Kx)      2b) substitute
            Kx(Kx)      2c) remove parens

             a  b       1) map abc
             ab.a       2a) lookup our pattern
             x          2b) substition

            END WHEN: there are no more SKIWBC... 
                      (in other words, all lowercase letters)
            
            Kx(CW) ... K-duplicates

            translate()

  B: abc.a(bc) 
  
        S(KS)Kx  
           a bc      1) map
           ac(bc)    2a) lookup 
           (KS)x(Kx) 2b) sub
           KSx(Kx)   2c) remove parens

            ab     1) map
            a      2) lookup
            S(Kx)  2b) sub
                 yz
              a  bc     1) map
              ac(bc)    2a) lookup
              (Kx)z(yz) 2b) sub
               Kxz(yz)  2c) remove parens

                ab
                ab.a
                x(yz) == a(bc)     
```
