/**
 * @param {string} code - The code to decipher
 * @returns {string} The deciphered PIN
 */
function decodeSantaPin(code) {
  // Code here
  let n;
  let ans = "";

  const op = {
    "+": () => n = (n+1 + 10) % 10, 
    "-": () => n = (n-1 + 10) % 10,
    "<": () => n = +ans.at(-1),
    "]": () => ans += n,
  }
  
  Array.from(code)
  .forEach((e) => {
    if (Number.isInteger(+e))
      n = +e;
  
    op[e]?.();
  });

  return ans.length < 4 ? null : ans;
}

