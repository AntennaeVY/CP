function checkPart(part) {
  const a = part.split("");
  const b = part.split("").reverse();

  if (a.join("") == b.join(""))
    return true;
  
  return a.some((e, i) => {
    const c = [...a];
    c.splice(i, 1);

    return c.join("") == c.reverse().join("");
  });
}
