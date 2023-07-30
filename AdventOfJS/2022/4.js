function fitsInOneBox(boxes) {
  return boxes.sort((a,b) => {
    return (a.l + a.w + a.h) - (b.l + b.w + b.h);
  }).every((a, i) => {
    if (i==0) return true;
    return a.l > boxes[i-1].l && a.w > boxes[i-1].w && a.h > boxes[i-1].h;
  })
  ;
}
