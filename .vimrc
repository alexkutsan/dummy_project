function! Build()
  silent :!clear
  silent :!mkdir -p build
  silent :!cd build && cmake .. && make 
  :!echo "Done"
  redraw!
endfunction
command! Build :call Build()

function! Clean()
  silent :!clear
  silent :!cd build && rm -frv *
  :!echo "Done"
  redraw!
endfunction
command! Clean :call Clean()

function! Run()
  silent :!clear
  silent :!cd build && ./project
  :!echo "Done"
  redraw!
endfunction
command! Run :call Run()

function! Test()
  silent :!clear
  silent :!cd build/test && ./ProjectTest; 
  silent :!cd build/test && ./CalculatorTest; 
  silent :!cd build/test && ./ParserTest; 
  :!echo "Done"
  redraw!
endfunction
command! Test :call Test()
