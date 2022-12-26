const SATURDAY = 0, SUNDAY = 6;

function countHours(year: number, holidays: string[]): number {
  let count = 0;

  for (const holiday of holidays) {
    const [month, day] = holiday.split("/").map(i => parseInt(i));
    const date = new Date(year, month-1, day);

    if (date.getDay() == SATURDAY || date.getDay() == SUNDAY)
      continue;
  
    count += 2;
  }

  return count;
}
