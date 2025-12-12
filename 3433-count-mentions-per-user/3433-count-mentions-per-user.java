import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    private String offline = "OFFLINE";
    private String all = "ALL";
    private String here = "HERE";

    public int[] countMentions(int n, List<List<String>> events) {
        events.sort((a, b) -> {
            int comparison = Integer.compare(Integer.parseInt(a.get(1)), Integer.parseInt(b.get(1)));

            if (comparison == 0) {
                if (offline.equalsIgnoreCase(a.get(0))) {
                    return -1;
                } else if (offline.equalsIgnoreCase(b.get(0))) {
                    return 1;
                }
            }
            return comparison;
        });

        HashMap<String, Integer> removeAt = new HashMap<>();

        int[] ans = new int[n];
        for (int i = 0; i < events.size(); i++) {
            var ev = events.get(i);
            if (offline.equalsIgnoreCase(ev.get(0))) {
                int endTime = Integer.parseInt(ev.get(1)) + 60;
                removeAt.put(ev.get(2), endTime);
            } else {
                int curr = Integer.parseInt(ev.get(1));
                removeExpiredOffline(removeAt, curr);
                if (all.equalsIgnoreCase(ev.get(2))) {
                    addAllMentions(ans);
                } else if (here.equalsIgnoreCase(ev.get(2))) {
                    addHereMentions(ans, removeAt, curr);
                } else {
                    addPersonalMentions(ans, removeAt, curr, ev.get(2));
                }
            }
        }
        return ans;
    }

    private void addAllMentions(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i]++;
        }
    }

    private void removeExpiredOffline(HashMap<String, Integer> remH, int curr) {
        var it = remH.entrySet().iterator();
        while (it.hasNext()) {
            var entry = it.next();
            if (entry.getValue() <= curr) {
                it.remove();
            }
        }
    }

    private void addHereMentions(int[] arr, HashMap<String, Integer> remH, int curr) {
        for (int i = 0; i < arr.length; i++) {
            var ind = String.valueOf(i);
            if (remH.containsKey(ind) && (remH.get(ind) > curr)) {
                continue;
            } else {
                arr[i]++;
            }
        }
    }

    private void addPersonalMentions(int[] arr, HashMap<String, Integer> remH, int curr, String text) {
        String regex = "(?<=id)(\\d+)";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(text);
        List<String> toAdd = new ArrayList<>();
        while (matcher.find()) {
            String extractedId = matcher.group(1);
            toAdd.add(extractedId);
        }
        for (String id : toAdd) {
            if (remH.containsKey(id) && (remH.get(id) < curr)) {
                continue;
            } else {
                arr[Integer.valueOf(id)]++;
            }
        }
    }
}