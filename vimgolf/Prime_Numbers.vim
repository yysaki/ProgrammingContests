function P()
  let l=[2]
  let x=3
  while len(l)<100
    let f=1
    for i in l
      if x%i==0
        let f=0
      endif
    endfor
    if f>0
      call add(l,x)
    endif
    let x=x+2
  endwhile
  return l
endfunction
