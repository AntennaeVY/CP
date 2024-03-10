function decode(message) {
  let ans = message, result;

  while(result = (/\(([a-zA-Z ]*?)\)/g).exec(ans)) {
    const l = result.index;
    const r = result.index + result[1].length + 1;

    const prefix = ans.slice(0, l);
    const middle = ans.slice(l+1, r);
    const suffix = ans.slice(r+1);

    ans = prefix + middle.split("").reverse().join("") + suffix;
  }

  return ans;
}
