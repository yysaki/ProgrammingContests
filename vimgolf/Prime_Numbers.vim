" vimgolf put 4d1c27940e3d7832db000010
" score: 138
fu! P()
  let l=[2]
  let x=3
  wh len(l)<100
    if empty(filter(copy(l),'x%v:val==0'))
      call add(l,x)
    en
    let x+=2
  endw
  retu l
endf
