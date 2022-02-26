#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Project {
public:
	ll numb;
	string name;
	ll duration;
	ll score;
	ll exp;
	ll roles;
	vector<pair<string, ll>> skills;
};


class con {
public:
	ll numb;
	string name;
	ll n_s;
	vector<ll> skills;
	con() {
		skills.assign(101, 0);
	}
};
bool comp(Project* a, Project* b) {
	if(a->exp==b->exp) {
		if(a->duration==b->duration) {
			return a->score>b->score;
		}
		return a->duration<b->duration; 
	}
	return a->exp<b->exp;
}

vector<Project*> projectmap;
vector<con*> conmap;
unordered_map<string, ll> skill;
unordered_map<ll, ll> available;
vector<unordered_set<ll>> skilledP(101);




int main() {
	ll c, p;
	cin>>c>>p;
	for(ll i=0; i<c; i++) {
		con* a = new con();
		a->numb = i;
		cin>>a->name>>a->n_s;
		for(ll i=0; i<a->n_s; i++) {
			string s;
			cin>>s;
			if(skill.find(s)==skill.end()) {
				skill[s] = skill.size();	
			}
			ll value = skill[s];
			cin>>a->skills[value];
			skilledP[value].insert(a->numb);
		}
		conmap.push_back(a);
		available[i] = 0;
	}
	for(ll i=0; i<p; i++) {
		Project* a = new Project();
		a->numb = i;
		cin>>a->name;
		cin>>a->duration;
		cin>>a->score>>a->exp>>a->roles;
		for(ll k=0; k<a->roles; k++) {
			string s;
			ll lev;
			cin>>s>>lev;
			a->skills.push_back({s, lev});
		}
		projectmap.push_back(a);
	}
	sort(projectmap.begin(), projectmap.end(), comp);
	vector<vector<string>> ans;
	for(auto &c: projectmap) {
		vector<ll> values(101,0);
		vector<ll> peop;
		bool ultpos = true;
		ll maxiT = 0;
		for(auto &p: c->skills) {
			ll skv = skill[p.first];
			bool possible = false;
			for(auto &ccc: skilledP[skv]) {
				if( find(peop.begin(), peop.end(), ccc)==peop.end() and available[ccc]+c->duration<=c->exp and (conmap[ccc]->skills[skv] >= p.second or (conmap[ccc]->skills[skv] == p.second-1 and values[skv]>=p.second))) {
					peop.push_back(ccc);
					values[skv] = max(values[skv], conmap[ccc]->skills[skv]);
					possible = true;
					maxiT = max(maxiT, available[ccc]+c->duration);
					break;
				}
			}
			if(!possible) {

				for(auto &ccc: skilledP[skv]) {
					if(find(peop.begin(), peop.end(), ccc)==peop.end() and conmap[ccc]->skills[skv] >= p.second or (conmap[ccc]->skills[skv] == p.second-1 and values[skv]>=p.second)) {
						peop.push_back(ccc);
						values[skv] = max(values[skv], conmap[ccc]->skills[skv]);
						possible = true;
						maxiT = max(maxiT, available[ccc]+c->duration);	
						break;
					}
				}
				if(!possible) {
					ultpos = false;
					break;
				}
			}

		}
		if(!ultpos) {
			continue;
		}else {
			ans.push_back({c->name});
			vector<string> anns;
			for(ll i=0; i<c->skills.size(); i++) {
				ll skv = skill[c->skills[i].first];
				ll numC = peop[i];
				if(conmap[numC]->skills[skv]<=c->skills[i].second) {
					conmap[numC]->skills[skv]++;
				}
				available[numC] = maxiT;
				anns.push_back(conmap[numC]->name);
			}
			ans.push_back(anns);
		}
	}
	cout<<ans.size()/2<<endl;;
	for(auto &c: ans) {
		for(auto &a: c) {
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}