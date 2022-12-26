function printTable(gifts) {
  const [mnl, mql] = gifts.reduce((p, c) => {
    return [Math.max(p[0], c.name.length),
    Math.max(p[1], Math.log10(c.quantity) + 1)]
  }, [4, 8]);

  let box = "";

  box += `++${"+".repeat(mnl)}+++${"+".repeat(mql)}++\n`;
  box += `| ${"Gift".padEnd(mnl)} | ${"Quantity".padEnd(mql)} |\n`;
  box += `| ${"-".repeat(mnl)} | ${"-".repeat(mql)} |\n`;

  gifts.forEach(({ name, quantity }) => {
    box += `| ${name.padEnd(mnl)} | ${String(quantity).padEnd(mql)} |\n`;
  });

  box += `**${"*".repeat(mnl)}***${"*".repeat(mql)}**`;

  return box;
}

