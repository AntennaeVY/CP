function organizeInventory(inventory) {
  const ans = {};

  inventory.forEach(({name, quantity, category}) => {
      ans[category] ||= {}
      ans[category][name] ??= 0
      ans[category][name] += quantity
  })

  return ans;
}
