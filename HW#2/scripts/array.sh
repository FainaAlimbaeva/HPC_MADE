#!/bin/bash
fruits=(apple banana orange melon lime mango plum papaya apricot peach)
for ((i=0; i<${#fruits[@]}; i++))
do
   echo $fruits[i]
done
 
