" vimgolf put 4d1c27940e3d7832db000010
" score: 83

for i in range(2, 541)
  if filter(range(2,i-1),'i%v:val==0')==[]
    pu=i
  en
endfo

" if this can be used
:pu=filter(range(2,541), "empty(filter(range(2,v:val-1),'v:val%v:val2==0'")

" if this can be used
fu P(i)
  filter(range(2,i-1),'i%v:val==0')==[]
endf
pu=filter(range(2,541),'P(v:val)')
