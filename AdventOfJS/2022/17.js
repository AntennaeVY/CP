function carryGifts(gifts, maxWeight) {
  return gifts
  .join(' ')
  .match(new RegExp(`\\b(\\w\\s?){1,${maxWeight}}(?=\\s|\$)`, 'g')) || [];
}
