import sys
import httpx
import json
import re
import os
import time

# Create output directory
OUTPUT_DIR = "adventjs_data"
os.makedirs(OUTPUT_DIR, exist_ok=True)

# ---------------------------------------------------------
# CONFIGURATION
# ---------------------------------------------------------
BASE_URL = "https://adventjs.dev/api/challenge-2025"

# UPDATED HEADERS: Removed 'br' from Accept-Encoding to prevent decoding errors
HEADERS = {
    "Host": "adventjs.dev",
    "Cookie": "__Host-next-auth.csrf-token=de728512495611ad19b52c34848543f0e2d135fede055570f698c8303928f61b%7C4bab5ac33c5d11b96ae07469da0a2d9a93d7e8c527c73d6a30eb6a70c43d6f69; __Secure-next-auth.callback-url=https%3A%2F%2Fadventjs.dev%2Fes%2Fchallenges%2F2025%2F1; cf_clearance=AelBSxfl1opEpK.F5dnS1JGwo7tYz1pPvfAZ54te0Dk-1764776702-1.2.1.1-TR990JqdU2HH4n9E3vnhZ5FM49n2_qjxUKT95o_izSrtwkoyLWTp6VrM6hn7DSJRqdJFlVDzqY7yoqKAG9sITR9LP41OCuNkfTZWi34ElbEIn7Xi3Jeyk3xsPfpGpOZkb0iNEXXVrh3tZ3WtarC891vdVWP4jJiZ0FSSCVAjFoGxZRDdgABAqoUZRm78tqBnzWwTl4ynOs0zyzszl8w7_I.KkQT.aP4gasIZncIteG0; __Secure-next-auth.session-token=eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..M5m_sku-x11GVdwH.K8htG1jDAiR-uaTjS3aMX0SxEOGVV18_soNwU4hEAjm7eiUW7MweXYvjyh-7x-flAw3w4KTsflBNMbBP0eF5Za3lkp3ujEc_q8yiEtnnbzs5GRBSpA72UMH_5u1dp1zdvtbNz03ajcwXu6TlaxLF5g-7aMPI8pJMdovHXGWb5GnVB-kuiy7uw68OYo21j0GJILZTUcCD5_r2KRAH_PM6EwwUH_7knTZg95Bedd62Gs-fwMD7kBJKgkXslFSwZ1sAnC0PtZt36nxhk4Kkn4Wv84sKPBmzmx1K7QojAuIN1njryR0NeGS6RTOBrXw_Q0J0gJdJa9Ijt2pQweuEamjDzvCkyPCWNO7UT7aDKMu6O_ao-C8fY6cg97e4aJdCFvwk5pE_gm4MbNTQabMYxT3FLbNwTADwp_juuA.wqhJCo64ojNfKVH9SRQzKg",
    "Sec-Ch-Ua-Platform": "\"Windows\"",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36",
    "Sec-Ch-Ua": "\"Chromium\";v=\"142\", \"Google Chrome\";v=\"142\", \"Not_A Brand\";v=\"99\"",
    "Dnt": "1",
    "Content-Type": "application/json",
    "Sec-Ch-Ua-Mobile": "?0",
    "Accept": "*/*",
    "Origin": "https://adventjs.dev",
    "Sec-Fetch-Site": "same-origin",
    "Sec-Fetch-Mode": "cors",
    "Sec-Fetch-Dest": "empty",
    "Referer": "https://adventjs.dev/es/challenges/2025/2",
    "Accept-Encoding": "gzip, deflate", # Removed 'br' to fix encoding error
    "Accept-Language": "es-ES,es;q=0.9,en;q=0.8,ru;q=0.7",
    "Priority": "u=1, i"
}

def solve_challenge(client, day_id):
    print(f"\n--- Processing Day {day_id} ---")
    url = f"{BASE_URL}/{day_id}"
    
    # -------------------------------------------------
    # STEP 1: Generic Request
    # -------------------------------------------------
    code_step_1 = "function FUNCTION(ARGUMENTS) {\n  const organized = {};\n\n return;\n}"
    payload_1 = {"code": code_step_1, "language": "javascript"}
    
    response_1 = client.post(url, json=payload_1)
    
    # Check for Rate Limit immediately
    if response_1.status_code == 429:
        raise Exception("Rate Limited (429). You need to wait longer.")

    match_name = re.search(r"use\s+(\w+)\s+as the function name", response_1.text)
    
    if not match_name:
        print(f"FAILED Step 1 for Day {day_id}: Status {response_1.status_code}")
        return

    func_name = match_name.group(1)
    print(f"Step 1 Success: Found function name '{func_name}'")
    
    # PAUSE to be polite
    time.sleep(10)

    # -------------------------------------------------
    # STEP 2: Find Arguments
    # -------------------------------------------------
    code_step_2 = f"function {func_name}(ARGUMENTS) {{\n  const organized = {{}};\n\n return;\n}}"
    payload_2 = {"code": code_step_2, "language": "javascript"}
    
    response_2 = client.post(url, json=payload_2)
    
    match_args = re.search(r"arguments:\s+(.*)", response_2.text)
    
    if not match_args:
        print(f"FAILED Step 2 for Day {day_id}: Status {response_2.status_code}")
        return

    func_args = match_args.group(1).strip()
    print(f"Step 2 Success: Found arguments '{func_args}'")
    
    # PAUSE to be polite
    time.sleep(10)

    # -------------------------------------------------
    # STEP 3: Final Request
    # -------------------------------------------------
    code_step_3 = f"function {func_name}({func_args}) {{\n  const organized = {{}};\n\n return;\n}}"
    payload_3 = {"code": code_step_3, "language": "javascript"}
    
    response_3 = client.post(url, json=payload_3)
    
    if response_3.status_code == 200:
        print(f"Step 3 Success: Valid response received.")
        
        # Save Request
        req_filename = os.path.join(OUTPUT_DIR, f"day_{day_id}_request.json")
        with open(req_filename, 'w', encoding='utf-8') as f:
            json.dump(payload_3, f, indent=2)
            
        # Save Response
        res_filename = os.path.join(OUTPUT_DIR, f"day_{day_id}_response.json")
        with open(res_filename, 'w', encoding='utf-8') as f:
            json.dump(response_3.json(), f, indent=2)
            
        print(f"Saved files for Day {day_id}")
    else:
        print(f"FAILED Step 3 for Day {day_id}: Status {response_3.status_code}")

def main():
    
    if (len(sys.argv) < 2):
        print("Usage: ./scrapper.py start_day")
        return

    start_day = int(sys.argv[1]) 

    # Use httpx.Client with http2=True
    with httpx.Client(http2=True, headers=HEADERS, timeout=15.0) as client:
        for i in range(start_day, 25):
            try:
                solve_challenge(client, i)
                # Significant delay between days to avoid 429
                print("Waiting 5 seconds before next challenge...")
                time.sleep(10) 
            except Exception as e:
                print(f"Error processing Day {i}: {e}")
                # If we hit an error, wait even longer just in case
                time.sleep(10)

if __name__ == "__main__":
    main()
