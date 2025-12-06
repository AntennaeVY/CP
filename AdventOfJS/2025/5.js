/**
 * @param {string} fromTime - The current time in elf format
 * @param {string} takeOffTime - The take off time in elf format
 * @returns {number} The time in seconds until take off
 */
function timeUntilTakeOff(fromTime, takeOffTime) {
  const m = {
    "*": "-",
    "@": "T",
    "|": ":",
    " ": "",
    "N": "",
    "P": ""
  }

  const ft = Array
    .from(fromTime)
    .map((c)=> m[c] !== undefined ? m[c] : c)
    .join("");

  const tt = Array
    .from(takeOffTime)
    .map((c)=> m[c] !== undefined ? m[c] : c)
    .join("");

  const fs = Math.floor(new Date(ft).getTime() / 1000);
  const ts =  Math.floor(new Date(tt).getTime() / 1000);

  return ts - fs;
}
